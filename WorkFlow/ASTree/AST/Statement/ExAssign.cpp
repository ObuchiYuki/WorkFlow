//
//  ExAssign.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Leaf.hpp"
#include "ExAssign.hpp"

using namespace wf::ast;


var AddAssignStem::target() const -> NodePtr {
    return children[0];
}

var AddAssignStem::value() const -> NodePtr {
    return children[1];
}

var AddAssignStem::description() const -> std::string {
    return "(" + target()->description() + " += " + value()->description() + ")";
}

var DecAssignStem::target() const -> NodePtr {
    return children[0];
}

var DecAssignStem::value() const -> NodePtr {
    return children[1];
}

var DecAssignStem::description() const -> std::string {
    return "(" + target()->description() + " += " + value()->description() + ")";
}
