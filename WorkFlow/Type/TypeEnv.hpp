//
//  TypeEnv.h
//  WorkFlow
//
//  Created by yuki on 2019/08/15.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef TypeEnv_h
#define TypeEnv_h

#include <vector>
#include <string>

#include "Type.hpp"
#include "Property.hpp"

namespace wf {namespace type {

class TypeEnvironment {
private:
    std::vector<PropertyPtr> properties = {};
    
public:
    
    auto registerProperty(PropertyPtr property) {
        
        properties.push_back(property);
    }
    
    auto getType(std::string name) -> wf::type::TypePtr {
        for (let& prop: properties) {
            if (prop->name == name){
                return prop->type;
            }
        }
        
        return nullptr;
    }
    
    TypeEnvironment() {}
    
};

}}


#endif /* TypeEnv_h */
