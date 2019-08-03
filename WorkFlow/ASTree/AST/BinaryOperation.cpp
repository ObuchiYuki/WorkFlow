//
//  BinaryOperation.cpp
//  WorkFlowa
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "BinaryOperation.hpp"

using namespace wf::ast;

auto BinaryOperator::right() -> NodePtr {
    return children[0];
}

auto BinaryOperator::left() -> NodePtr {
    return children[2];
}

auto BinaryOperator::op() -> NodePtr {
    return children[1];
}
    
BinaryOperator::BinaryOperator(std::vector<NodePtr> _children, Location _location) :
Node(_children, _location)
{};
