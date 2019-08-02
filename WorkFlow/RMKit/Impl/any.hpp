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
#include <cxxabi.h>

namespace rm {

// MARK: - any -

class any {
private:
    // ==============================================================================//
    // MARK: - Private -
    
    // MARK: - Private Classes -
    /// Any型にテンプレートのない中身を提供します。
    struct _any_base {
        virtual ~_any_base() {}
        virtual _any_base* clone() const = 0;
        virtual std::type_info const& type() const = 0;

    };
        
    /// Any型のタイプを削除します。
    template<class T>
    struct _any : public _any_base {
    private:
        /// 実際の値
        T _value;
        
    public:
        // MARK: - Constructor -
        _any(T __value) :
        _value(__value) {}
        
        _any_base* clone() const override {
            return new _any<T>(_value);
        }
        std::type_info const& type() const override {
            return typeid(T);
        }
    };
    
    // MARK: - Private Methods -
    static char* demangle(const char *demangle) {
        int status;
        return abi::__cxa_demangle(demangle, 0, 0, &status);
    }
        
    // MARK: - Private Field -
    std::shared_ptr<_any_base> _obj;

    // ==============================================================================//
    // MARK: - public -
    public:
    
    // MARK: - Methods -
    std::type_info const& type() const {
        return _obj->type();
    }
    
    // MARK: - Constructor -
    template<class T>
    any (const T& value) {
        _obj.reset(new _any<T>(value));
    }
        
    any (const any& a) {
        if (a._obj) {
            _obj.reset(a._obj->clone());
        } else {
            _obj = nullptr;
        }
    }
    
    // MARK: - Operators - 
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
    any& operator = (const T& value) {
        _obj = new _any<T>(value);
        return *this;
    }
        
    template<class T>
    const T& cast() const {
        return dynamic_cast< _any<T>& >(*_obj)._value;
    }
    
    friend std::ostream& operator << (std::ostream &os, const any a) {
        const auto name = demangle(a.type().name());
        
        os << "any<" << name << ">";
        
        delete name;
            
        return os;
    }
};

}


#endif /* any_h */
