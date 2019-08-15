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
        
        Type::global->registerType(Int);
        Type::global->registerType(Bool);
        Type::global->registerType(String);
        Type::global->registerType(Array);
        Type::global->registerType(Dictionary);
        Type::global->registerType(Float);
    }
};

}}


#endif /* PrimitiveType_h */
