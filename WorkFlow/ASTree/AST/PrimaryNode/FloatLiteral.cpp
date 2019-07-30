//
//  FloatLiteral.cpp
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

auto FloatLiteral::value() -> float const {
    return std::stod(child()->token->value);
}

FloatLiteral::FloatLiteral(std::vector<NodePtr> _children, Location _location) :
PrimaryNode(_children, _location)
{};

auto FloatLiteral::description() -> std::string const{
    return child()->token->value;
}
