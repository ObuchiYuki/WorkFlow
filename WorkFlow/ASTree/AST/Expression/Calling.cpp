//
//  Calling.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/01.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Calling.hpp"
#include "Statement.hpp"

#include <exception>

#include "WorkFlowError.hpp"

using namespace wf::ast;

Calling::Calling(std::vector<NodePtr> _children, Location _location) :
Expression(_children, _location) {}

auto Calling::target() const -> NodePtr{
    return children[0];
}

auto Calling::args() const -> NodePtr {
    if (numChildren() == 2){
        return children[1];
    }
    return nullptr;
}

auto Calling::description() const -> std::string {
    return "(" + target()->description() + "(" + args()->description() + ")" + ")";
}

auto Calling::eval(wf::run::Environment& env) const -> wf::run::Value {
    let leaf = nodeAsLeaf(target());
    
    if (!leaf) return wf::run::Value::voidValue();
    
    let fnname = leaf->token->value;
    
    if (fnname == "prints") {
        if (!args()) throw wf::WorkFlowError("Function \"prints\" require 1 argument.");
        
        print(args()->eval(env).string());
    }else if (fnname == "printi") {
        if (!args()) throw wf::WorkFlowError("Function \"printi\" require 1 argument.");
        
        print(args()->eval(env).integer());
        
    }else{
        let calling =  std::dynamic_pointer_cast<wf::ast::Calling>(env.get(fnname).runnable());

        
        throw wf::WorkFlowError("Build-in funtion named " + fnname + " not found.");
    }
    
    return wf::run::Value::voidValue();
}
