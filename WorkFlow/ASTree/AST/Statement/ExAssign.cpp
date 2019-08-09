//
//  ExAssign.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Leaf.hpp"
#include "ExAssign.hpp"

using namespace wf::ast;


var AddAssignStem::target() const -> NodePtr {
    return children[0];
}

var AddAssignStem::value() const -> NodePtr {
    return children[1];
}

var AddAssignStem::description() const -> std::string {
    return "(" + target()->description() + " += " + value()->description() + ")";
}

auto AddAssignStem::eval(wf::run::Environment& env) const -> wf::run::Value {
    
    let s_target = nodeAsLeaf(target())->token->value;
    var r_value = target()->eval(env).integer() + value()->eval(env).integer();
    
    env.set(s_target, wf::run::Value(r_value));
    
    return wf::run::Value::voidValue();
}

