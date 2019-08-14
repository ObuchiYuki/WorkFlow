//
//  Expression.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Expression.hpp"
#include "WorkFlowError.hpp"

#include <memory>
#include <vector>

using namespace wf::ast;

auto Expression::description() const -> std::string {
    
    return children[0]->description();
}
auto Expression::returnTyep() const -> TypePtr {
    throw wf::WorkFlowError("[Expression::returnTyep] 'this' method must be overrided to return type.");
}

Expression::Expression(std::vector<NodePtr> _children, Location _location) :
Node(_children, _location)
{}
