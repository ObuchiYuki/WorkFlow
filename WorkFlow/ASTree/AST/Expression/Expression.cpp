//
//  Expression.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Expression.hpp"

#include <memory>
#include <vector>

using namespace wf::ast;

auto Expression::description() -> std::string const {
    return children[0]->description();
}

Expression::Expression(std::vector<NodePtr> _children, Location _location) :
Node(_children, _location)
{}
