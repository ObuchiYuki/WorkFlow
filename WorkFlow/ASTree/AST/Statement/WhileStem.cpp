//
//  WhileStem.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/01.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "WhileStem.hpp"

using namespace wf::ast;

auto WhileStem::condition() const -> NodePtr {
    return children[0];
}
auto WhileStem::block() const -> NodePtr {
    return children[1];
}

WhileStem::WhileStem(std::vector<NodePtr> _children, Location _location) :
Node(_children, _location) {}

auto WhileStem::description() const -> std::string {
    return "(while " + condition()->description() + " " + block()->description() + ")";
}
