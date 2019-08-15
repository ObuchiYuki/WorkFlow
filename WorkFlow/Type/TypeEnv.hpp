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

class TypeEnvironment :public Type {
public:
    
    TypeEnvironment(std::string _name, TypePtr _parent) : Type(_name, _parent) {}
    TypeEnvironment(std::string _name) : Type(_name) {}
};

}}


#endif /* TypeEnv_h */
