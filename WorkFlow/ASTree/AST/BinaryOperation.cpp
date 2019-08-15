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
#include "WorkFlowError.hpp"

using namespace wf::ast;

auto BinaryOperation::left() const -> ExpressionPtr {
    
    return std::dynamic_pointer_cast<Expression>(children[0]);
}

auto BinaryOperation::right() const -> ExpressionPtr {
    
    return std::dynamic_pointer_cast<Expression>(children[2]);
}

auto BinaryOperation::op(wf::type::TypeEnvironment& env) -> type::FunctionTypePtr {
    let name = nodeAsLeaf(children[1])->token->value;
    
    for (let& prop: type::Type::global->properties){
        let funp = std::dynamic_pointer_cast<type::FunctionType>(prop->type);
        if(funp == nullptr) continue;
                
        if (prop->name == name && funp->match({left()->returnType(env), right()->returnType(env)})) {
            _checkedOp = funp;
            return funp;
        }
    }
    
    throw WorkFlowError("BinaryOperation: Operator (" + left()->returnType(env)->description() + " '" +
                        name + "' " + right()->returnType(env)->description() +
                        ") is not defined.");
}

auto BinaryOperation::description() const -> std::string {
    let name = nodeAsLeaf(children[1])->token->value;
    
    return "(" + left()->description() + " ('" + name + "'" + _checkedOp->description() + ") " + right()->description() + ")";
}
