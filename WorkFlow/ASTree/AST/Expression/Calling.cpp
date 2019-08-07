//
//  Calling.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/01.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Calling.hpp"

#include <exception>

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

auto Calling::eval(wf::run::Environment& env) -> wf::run::Value {
    let leaf = nodeAsLeaf(target());
    
    if (!leaf) return wf::run::Value::voidValue();
    
    let fnname = leaf->token->value;
    if (fnname == "prints") {
        
        print(args()->eval(env).string());
    }else if (fnname == "printi") {
        print(args()->eval(env).integer());
    }else{
        throw std::runtime_error("Build-in funtion named " + fnname + " not found.");
    }
    
    return wf::run::Value::voidValue();
}
