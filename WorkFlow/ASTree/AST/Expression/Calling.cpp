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

#include "Function.hpp"
#include "WorkFlowError.hpp"
#include "Argument.hpp"
#include "ArgumentList.hpp"
#include "TypeUmbrella.hpp"

using namespace wf::ast;

Calling::Calling(std::vector<NodePtr> _children, Location _location) :
Expression(_children, _location) {}

auto Calling::target() const -> std::string {
    
    return std::dynamic_pointer_cast<Name>(children[0])->token->value;
}

auto Calling::args() const -> std::shared_ptr<ArgumentList> {
    if (numChildren() == 2){ // argあり
        return std::dynamic_pointer_cast<ArgumentList>(children[1]);
    }
    return nullptr;
}

var Calling::returnType(wf::type::TypeEnvironment& env) -> type::TypePtr {
    let func_type = std::dynamic_pointer_cast<type::FunctionType>(env.getType(target()));
    
    return func_type->returnType;
}

auto Calling::description() const -> std::string {
    return "(" + target() + "(" + args()->description() + ")" + ")->(" + _checkedReturn->description() + ")";
}
