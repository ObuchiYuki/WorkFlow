//
//  any.h
//  RMKit
//
//  Created by yuki on 2019/08/02.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef rm_any_h
#define rm_any_h

#include <typeinfo>
#include <memory>
#include <string>
#include <cxxabi.h>
#include <exception>
#include <stdexcept>

#include "typeinfo.hpp"
#include "optional.hpp"

namespace rm {

/**
 あらゆるものが入る型を表します。
 型を無効化するツールなので、多くの場合は使用は推奨されません。
 
 -- 使用　--
 ```
 rm::any value;
 
 value = 100;
 value = 3.14;
 value = "Hello";
 
 vector<rm::any> list;
 
 list.push_back(100);
 list.push_back(3.14);
 list.push_back("World");

 */
class any {
// ==============================================================================//
// MARK: - Private -
private:
    
    // MARK: - Private Classes -
    /// Any型にテンプレートのない中身を提供します。
    /// Abstruct class です。
    struct _any_base {
        virtual ~_any_base() {}
        virtual _any_base* clone() const = 0;
        virtual std::type_info const& type() const = 0;

    };
        
    /// Any型のタイプを削除します。
    template<class T>
    struct _any : public _any_base {
        /// 実際の値
        T _value;
        
        // MARK: - Constructor -
        
        /// 値から初期化します。
        _any(T __value) : _value(__value) {}
        
        /// 自身のクローンを作成します。
        _any_base* clone() const override {
            return new _any<T>(_value);
        }
        /// 自身の型情報を返します。
        std::type_info const& type() const override {
            return typeid(T);
        }
    };
    
    // MARK: - Private Methods -
    
    /// 型名をデマングルします。
    static std::string demangle(const char *demangle) {
        int status;
        auto rawName = abi::__cxa_demangle(demangle, 0, 0, &status);
        auto result = std::string(rawName);
        
        delete rawName;
        return result;
    }
        
    // MARK: - Private Field -
    
    /// ホルダーの値です。
    std::shared_ptr<_any_base> _obj;

    // ==============================================================================//
    // MARK: - public -
    public:
    
    // MARK: - Methods -
    
    /// 自身の型情報を返します。
    std::type_info const& type() const {
        return _obj->type();
    }
    
    const std::string type_name() const {
        return demangle(type().name());
    }
    
    // MARK: - Constructor -
    
    /// 値から初期化します。
    template<class T>
    any (const T& value) {
        _obj.reset(new _any<T>(value));
    }
    
    /// コピーコンストラクター
    any (const any& a) {
        if (a._obj) {
            _obj.reset(a._obj->clone());
        } else {
            _obj = nullptr;
        }
    }
    
    // MARK: - Operators -
    
    /// 代入演算子
    any& operator = (const any& a) {
        if (a._obj) {
            _obj.reset(a._obj->clone());
        }
        else {
            _obj = nullptr;
        }
        return *this;
    }
        
    template<class T>
    
    /// 値からの代入演算子
    any& operator = (const T& value) {
        _obj = new _any<T>(value);
        return *this;
    }
        
    template<class T>
    /// 自身をキャストして返却します。失敗したら例外を投げます 。
    T as() const {
        const auto casted = dynamic_cast<_any<T>*>(_obj.get());
                        
        if (!casted){
            throw std::runtime_error("Cannot cast value type \"" + type_name() + "\" to type \"" + rm::type::type_name<T>() + "\"");
        }
        return casted->_value;
    }
    
    /// For print Operation.
    friend std::ostream& operator << (std::ostream &os, const any a) {
        os << "any<" << a.type_name() << ">";
            
        return os;
    }
};

}


#endif /* any_h */
