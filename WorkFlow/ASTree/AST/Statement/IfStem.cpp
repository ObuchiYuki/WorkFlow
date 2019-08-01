//
//  IfStem.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/31.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Statement.hpp"

using namespace wf::ast;

auto IfStem::condition() -> NodePtr {
    return children[0];
}

auto IfStem::block() -> NodePtr {
    return children[1];
}

auto IfStem::description() -> std::string const {
    return "(if " + condition()->description() + " " + block()->description() + ")";
}

IfStem::IfStem(std::vector<NodePtr> _children, Location _location) :
Node(_children, _location) {}


