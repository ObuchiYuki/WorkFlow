//
//  FuncStem.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/08.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "FuncStem.hpp"
#include "Function.hpp"

using namespace wf::ast;

var FuncStem::name() const -> std::shared_ptr<Name> {
    
    return std::dynamic_pointer_cast<ast::Name>(children[0]);
}
var FuncStem::parameters() const -> std::shared_ptr<wf::ast::ParameterList> {
    
    return std::dynamic_pointer_cast<ast::ParameterList>(children[1]);
}
var FuncStem::body() const -> std::shared_ptr<wf::ast::BlockStem> {
    
    return std::dynamic_pointer_cast<ast::BlockStem>(children[2]);
}

auto FuncStem::eval(wf::run::EnvironmentPtr env)  const-> wf::run::Value {
    
    let func = std::shared_ptr<wf::run::Function>(new wf::run::Function(name(), parameters(), body()));
    env->set(func->identifier, wf::run::Value(func));
    
    return wf::run::Value::voidValue();
}
