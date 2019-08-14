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
#include "Argument.hpp"
#include "ArgumentList.hpp"
#include "Function.hpp"

using namespace wf::ast;

Calling::Calling(std::vector<NodePtr> _children, Location _location) :
Expression(_children, _location) {}

auto Calling::target() const -> std::shared_ptr<Name> {
    
    return std::dynamic_pointer_cast<Name>(children[0]);
}

auto Calling::args() const -> std::shared_ptr<ArgumentList> {
    if (numChildren() == 3){ // argあり
        return std::dynamic_pointer_cast<ArgumentList>(children[1]);
    }
    return nullptr;
}

var Calling::returnTyep() const -> type::TypePtr {
    let index = (numChildren() == 3) ? 2 : 1;
    let name = nodeAsLeaf(children[index])->token->value;
    
    return type::TypePtr(new type::Type(name));
}

auto Calling::description() const -> std::string {
    return "(" + target()->description() + "(" + args()->description() + ")" + ")";
}

auto Calling::eval(wf::run::EnvironmentPtr env) const -> wf::run::Value {
    
    let id = wf::run::Function::createIdentifier(target()->token->value, *args());
    
    if (id == "prints()") {
        print(args()->arg(0)->value()->eval(env).string());
        
        return wf::run::Value::voidValue();
    }else if (id == "printi()") {
        print(args()->arg(0)->value()->eval(env).integer());
        
        return wf::run::Value::voidValue();
    }else{
        let func = env->get(id)._value.as<std::shared_ptr<wf::run::Function>>();
        return func->call(args(), env);
    }
}
