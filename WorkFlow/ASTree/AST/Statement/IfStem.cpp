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

auto IfStem::elseBlock() -> NodePtr {
    if (numChildren() == 3) {
        return children[2]->children[0];
    }
    return nullptr;
}

auto IfStem::description() -> std::string const {
    if (elseBlock() != nullptr) {
        return "(if " + condition()->description() + " " + block()->description() + ")" +
        "(else)" + elseBlock()->description() + ")";
    }else{
        return "(if " + condition()->description() + " " + block()->description() + ")";
    }
    
}

IfStem::IfStem(std::vector<NodePtr> _children, Location _location) :
Node(_children, _location) {}


