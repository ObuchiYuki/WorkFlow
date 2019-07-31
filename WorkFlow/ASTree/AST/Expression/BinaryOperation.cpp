//
//  BinaryOperation.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Expression.hpp"

using namespace wf::ast;

auto BinaryOperation::right() -> NodePtr {
    return children[0];
}

auto BinaryOperation::left() -> NodePtr {
    return children[2];
}

auto BinaryOperation::op() -> NodePtr {
    return children[1];
}

BinaryOperation::BinaryOperation(std::vector<NodePtr> _children, Location _location) :
Expression(_children, _location)
{}

auto BinaryOperation::description() -> std::string const {
    return "(" + right()->description() + " " + op()->description() + " " + left()->description() + ")"; 
}
