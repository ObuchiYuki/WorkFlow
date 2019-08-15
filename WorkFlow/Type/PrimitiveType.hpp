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
#include "FunctionType.hpp"

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
    
    static auto registerAll() -> void;
};

}}


#endif /* PrimitiveType_h */
