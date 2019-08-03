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
class type {
private:
    // Result is in heap memory. Deallocate after use.
    static char* type_name_demangle(const char* demangle) {
        int status;
        return abi::__cxa_demangle(demangle, 0, 0, &status);
    }
    
    static std::string get_type_name(const char* rawname) {
        auto typeNameChars = type_name_demangle(rawname);
        
        auto realTypeName = std::string(typeNameChars);
        
        delete typeNameChars;
        
        return realTypeName;
    }
public:
    
    /// Returns if given types equal.
    template<typename T, typename S>
    static const bool equals() {
        return typeid(T) == typeid(S);
    }
    
    /// Returns the name of the type
    template<typename T>
    static const std::string type_name() {
        
        return get_type_name(typeid(T).name());
    }
    
    
    template<typename T>
    static const std::string type_name(T value) {
        
        return get_type_name(typeid(value).name());
    }
};

}


#endif /* type_h */
