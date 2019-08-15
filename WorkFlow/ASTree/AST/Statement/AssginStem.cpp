//
//  AssginStem.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "AssginStem.hpp"
#include "Leaf.hpp"

using namespace wf::ast;

var AssginStem::target() const -> NodePtr {
    return children[0];
}
var AssginStem::value() const -> NodePtr{
    return children[2];
}

var AssginStem::description() const -> std::string {
    return "(" + target()->description() + " = " + value()->description() + ")";
}

