//
//  Calling.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/01.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Expression.hpp"

using namespace wf::ast;

Calling::Calling(std::vector<NodePtr> _children, Location _location) :
Expression(_children, _location) {}

auto Calling::target() -> NodePtr{
    return children[0];
}

auto Calling::args() -> NodePtr {
    return children[1];
}

auto Calling::description() -> std::string const {
    return "(" + target()->description() + "(" + args()->description() + ")" + ")";
}

auto Calling::eval(wf::run::Environment env) -> wf::run::Value {
    let leaf = nodeAsLeaf(target());
    
    if (!leaf) return wf::run::Value::voidValue();
    
    let fnname = leaf->token->value;
    if (fnname == "print") {

        print(args()->eval(env).string());
        
    }
    
    return wf::run::Value::voidValue();
}
