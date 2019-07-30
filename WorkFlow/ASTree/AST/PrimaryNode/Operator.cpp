//
//  Operator.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "PrimaryNode.hpp"

#include <memory>
#include <vector>

using namespace wf::ast;

// MARK: - Impl


auto Operator::value() -> std::string const {
    return child()->token->value;
}

Operator::Operator(std::vector<NodePtr> _children, Location _location) :
PrimaryNode(_children, _location)
{}

auto Operator::description() -> std::string const {
    return "(" + value() + "(";
}
