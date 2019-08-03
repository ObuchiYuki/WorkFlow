//
//  IntegerLiteral.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "PrimaryNode.hpp"

using namespace wf::ast;

auto IntegerLiteral::value() -> int const {
        
    return std::stoi(token->value);
}

IntegerLiteral::IntegerLiteral(std::vector<NodePtr> _children, Location _location) :
PrimaryNode(_children, _location)
{}
