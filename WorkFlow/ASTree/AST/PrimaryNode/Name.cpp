//
//  Name.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "PrimaryNode.hpp"

#include <memory>
#include <vector>

using namespace wf::ast;

auto Name::value() -> std::string const {
    return child()->token->value;
}

Name::Name(std::vector<NodePtr> _children, Location _location) :
PrimaryNode(_children, _location)
{}

auto Name::description() -> std::string const {
    return value();
}
