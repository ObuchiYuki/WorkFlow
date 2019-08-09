//
//  VarStem.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/04.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "VarStem.hpp"

using namespace wf::ast;

var VarStem::target() const -> NodePtr {
    return children[0];
}
var VarStem::init() const -> NodePtr {
    return children[1];
}

VarStem::VarStem(std::vector<NodePtr> _children, Location _location) :
Node(_children, _location) {};

var VarStem::description() const -> std::string {
    return "(def " + target()->description() + " = " + init()->description() + ")";
}

auto VarStem::eval(wf::run::Environment& env) const -> wf::run::Value {
    let s_target = nodeAsLeaf(target())->token->value;
    var r_value = init()->eval(env);

    env.set(s_target, r_value);
    
    
    return wf::run::Value::voidValue();
}
