//
//  varStem.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/04.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "VarStem.hpp"
#include "Leaf.hpp"

using namespace wf::ast;

var varStem::target() const -> std::string {
    
    return nodeAsLeaf(children[0])->token->value;
}

var varStem::init() const -> NodePtr {
    
    if (typeSpecifier() == nullptr) {
        return children[1];
    }else{
        return children[2];
    }
}

var varStem::typeSpecifier() const -> std::shared_ptr<TypeSpecifier> {
    return std::dynamic_pointer_cast<TypeSpecifier>(children[1]);
    
}

varStem::varStem(std::vector<NodePtr> _children, Location _location) :
Node(_children, _location) {};

var varStem::description() const -> std::string {
    return "(def " + target() + " = " + init()->description() + ")";
}

auto varStem::eval(wf::run::EnvironmentPtr env) const -> wf::run::Value {
    let s_target = target();
    var r_value = init()->eval(env);

    env->set(s_target, r_value);
    
    
    return wf::run::Value::voidValue();
}
