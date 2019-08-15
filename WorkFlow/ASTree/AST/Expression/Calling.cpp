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

auto Calling::target() const -> std::shared_ptr<Name> {
    
    return std::dynamic_pointer_cast<Name>(children[0]);
}

auto Calling::args() const -> std::shared_ptr<ArgumentList> {
    if (numChildren() == 3){ // argあり
        return std::dynamic_pointer_cast<ArgumentList>(children[1]);
    }
    return nullptr;
}

var Calling::returnType(wf::type::TypeEnvironment& env) const -> type::TypePtr {
    let index = (numChildren() == 3) ? 2 : 1;
    let name = nodeAsLeaf(children[index])->token->value;
    
    return type::TypePtr(new type::Type(name));
}

auto Calling::description() const -> std::string {
    return "(" + target()->description() + "(" + args()->description() + ")" + ")";
}
