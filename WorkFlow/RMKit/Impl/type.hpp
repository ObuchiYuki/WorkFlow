//
//  type.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/03.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef type_h
#define type_h

#include <string>
#include <typeinfo>

namespace rm {

/// 型名の比較など型情報に関する処理を提供します。
class type {
private:
    // 型名をデマングルします。
    static std::string demangle_type_name(const char* undemangled) {
        int status;
        auto char_list = abi::__cxa_demangle(undemangled, 0, 0, &status);
        
        auto result = std::string(char_list);
        delete char_list;
        
        return result;
    }
public:
    
    /// テンプレートに与えられた型が等しいかを比較します。
    template<typename T, typename S>
    static const bool equals() {
        return typeid(T) == typeid(S);
    }
    
    /// テンプレート型の型名を取得します。
    template<typename T>
    static const std::string type_name() {
        
        return demangle_type_name(typeid(T).name());
    }
    
    
    /// 引数の型名を取得します。
    template<typename T>
    static const std::string type_name(T value) {
        
        return demangle_type_name(typeid(T).name());
    }
};

}


#endif /* type_h */
