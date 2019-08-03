//
//  BinaryOperation.cpp
//  WorkFlowa
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "BinaryOperation.hpp"

using namespace wf::ast;

auto BinaryOperation::right() -> NodePtr {
    return children[2];
}

auto BinaryOperation::left() -> NodePtr {
    return children[0];
}

auto BinaryOperation::op() -> NodePtr {
    return children[1];
}
    
BinaryOperation::BinaryOperation(std::vector<NodePtr> _children, Location _location) :
Node(_children, _location)
{};


Value BinaryOperation::eval(wf::run::Environment env) {
    let op_s = wf::ast::nodeAsLeaf(op())->token->value;
    let lsh = left()->eval(env);
    let rsh = right()->eval(env);

    if (op_s == "<") {
        return Value(lsh.integer() < rsh.integer());
    }else if (op_s == ">") {
        return Value(lsh.integer() > rsh.integer());
    }
    
    return Value::voidValue();
}
