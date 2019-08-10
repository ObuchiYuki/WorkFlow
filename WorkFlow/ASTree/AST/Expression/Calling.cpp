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

using namespace wf::ast;

Calling::Calling(std::vector<NodePtr> _children, Location _location) :
Expression(_children, _location) {}

auto Calling::target() const -> NodePtr{
    return children[0];
}

auto Calling::args() const -> std::shared_ptr<ArgumentList> {
    if (numChildren() == 2){
        return std::dynamic_pointer_cast<ArgumentList>(children[1]);
    }
    return nullptr;
}

auto Calling::description() const -> std::string {
    return "(" + target()->description() + "(" + args()->description() + ")" + ")";
}

auto Calling::eval(wf::run::EnvironmentPtr env) const -> wf::run::Value {
    let leaf = nodeAsLeaf(target());
    
    if (!leaf) return wf::run::Value::voidValue();
    
    let fnname = leaf->token->value;
    
    
    return wf::run::Value::voidValue();
}
