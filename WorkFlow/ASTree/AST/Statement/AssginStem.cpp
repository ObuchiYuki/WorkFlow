//
//  AssginStem.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "AssginStem.hpp"

using namespace wf::ast;

var AssginStem::target() -> NodePtr {
    return children[0];
}
var AssginStem::value() -> NodePtr{
    return children[2];
}

var AssginStem::description() -> std::string const override {
    return "(" + target()->description() + " = " + value()->description() + ")";
}

wf::run::Value AssginStem::eval(wf::run::Environment& env) override {
    let s_target = nodeAsLeaf(target())->token->value;
    var r_value = value()->eval(env);

    env.set(s_target, r_value);
    
    return wf::run::Value::voidValue();
}
