//
//  NegativeExpr.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/01.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Expression.hpp"

using namespace wf::ast;

NegativeExpr::NegativeExpr(std::vector<NodePtr> _children, Location _location) :
Expression(_children, _location) {}

auto NegativeExpr::description() -> std::string const {
    return "";
    //return "-" + children[0]->description();
}
