//
//  Leaf.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Leaf.hpp"

using namespace wf::ast;

Leaf::Leaf(std::shared_ptr<wf::token::Token> _token, Location _location):
Node({}, _location) ,token(_token) {
    
}

auto Leaf::description() const -> std::string {
    return "[Leaf undefined]";
}

auto Leaf::eval(wf::run::EnvironmentPtr env) const -> wf::run::Value {
    return wf::run::Value(token->value);
}

auto Leaf::llvm() const -> std::string {
    rm::debug::warn("[Leaf::llvm] Leaf with no class have no LLVM. Or you may forget to override llvm. This node return comment.");
    
    return "; Leaf with no class. Value is " + token->value + ". Something Wrong.";
}
