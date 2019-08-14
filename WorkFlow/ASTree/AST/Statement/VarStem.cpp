//
//  VarStem.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/04.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "VarStem.hpp"
#include "Leaf.hpp"

using namespace wf::ast;

var VarStem::valueType() -> type::TypePtr {
    return init()->returnType();
}

var VarStem::target() const -> std::string {
    
    return nodeAsLeaf(children[0])->token->value;
}

var VarStem::init() const -> NodePtr {
    return children[1];
}


VarStem::VarStem(std::vector<NodePtr> _children, Location _location) :
Node(_children, _location) {};

var VarStem::description() const -> std::string {
    return "(def " + target() + " = " + init()->description() + ")";
}

auto VarStem::eval(wf::run::EnvironmentPtr env) const -> wf::run::Value {
    let s_target = target();
    var r_value = init()->eval(env);

    env->set(s_target, r_value);
    
    return wf::run::Value::voidValue();
}
