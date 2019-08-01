//
//  WhileStem.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/01.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Statement.hpp"

using namespace wf::ast;

auto WhileStem::condition() -> NodePtr {
    return children[0];
}
auto WhileStem::block() -> NodePtr {
    return children[1];
}
WhileStem::WhileStem(std::vector<NodePtr> _children, Location _location) :
Node(_children, _location) {}

auto WhileStem::description() -> std::string const {
    return "(while " + condition()->description() + " " + block()->description() + ")";
}
