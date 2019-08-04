//
//  VarStem.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/04.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Statement.hpp"

using namespace wf::ast;

var VarStem::target() -> NodePtr {
    return children[0];
}
var VarStem::init() -> NodePtr {
    return children[1];
}

VarStem::VarStem(std::vector<NodePtr> _children, Location _location) :
Node(_children, _location) {};

var VarStem::description() -> std::string const {
    return "(def " + target()->description() + " = " + init()->description() + ")";
}

auto VarStem::eval(wf::run::Environment& env) -> wf::run::Value {
    let s_target = nodeAsLeaf(target())->token->value;
    var r_value = init()->eval(env);

    env.set(s_target, r_value);
    
    
    return wf::run::Value::voidValue();
}
