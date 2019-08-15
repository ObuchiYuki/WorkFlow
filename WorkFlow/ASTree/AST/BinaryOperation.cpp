//
//  BinaryOperation.cpp
//  WorkFlowa
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#include <memory>

#include "BinaryOperation.hpp"
#include "Leaf.hpp"
#include "Expression.hpp"

using namespace wf::ast;

auto BinaryOperation::left() const -> ExpressionPtr {
    
    return std::dynamic_pointer_cast<Expression>(children[0]);
}

auto BinaryOperation::right() const -> ExpressionPtr {
    
    return std::dynamic_pointer_cast<Expression>(children[2]);
}

auto BinaryOperation::op() const -> wf::type::OperationPtr {
    let name = nodeAsLeaf(children[1])->token->value;
    
    return type::Type::global->searchOperation(name, left()->returnType(), right()->returnType());
}

auto BinaryOperation::description() const -> std::string {
    return "";
    //return "(" + left()->description() + " " + op()->description() + " " + right()->description() + ")";
}
