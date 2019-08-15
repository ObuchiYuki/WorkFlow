//
//  PrimitiveType.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/15.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef PrimitiveType_h
#define PrimitiveType_h

#include "Type.hpp"
#include "TypeManager.hpp"

namespace wf {namespace type{

/// Contains all primitive types
class PrimitiveType {
public:
    
    static TypePtr Int;
    static TypePtr Bool;
    static TypePtr String;
    static TypePtr Array;
    static TypePtr Dictionary;
    static TypePtr Float;
    
    PrimitiveType() {
        TypeManager::shared.registerType(Int);
        TypeManager::shared.registerType(Bool);
        TypeManager::shared.registerType(String);
        TypeManager::shared.registerType(Array);
        TypeManager::shared.registerType(Dictionary);
        TypeManager::shared.registerType(Float);
    }
};

}}


#endif /* PrimitiveType_h */
