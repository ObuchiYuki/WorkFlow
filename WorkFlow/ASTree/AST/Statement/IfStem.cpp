//
//  IfStem.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/31.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "IfStem.hpp"

using namespace wf::ast;

auto IfStem::condition() const -> std::shared_ptr<Expression> {
    
    return std::dynamic_pointer_cast<Expression>(children[0]);
}

auto IfStem::block() const -> std::shared_ptr<BlockStem> {
    
    return std::dynamic_pointer_cast<BlockStem>(children[1]);
}

auto IfStem::elseBlock() const -> NodePtr {
    if (numChildren() == 3) {
        return children[2];
    }
    return nullptr;
}

auto IfStem::description() const -> std::string {
    if (elseBlock() != nullptr) {
        return "(if " + condition()->description() + " " + block()->description() + ")" +
        "(else)" + elseBlock()->description() + ")";
    }else{
        return "(if " + condition()->description() + " " + block()->description() + ")";
    }
    
}

IfStem::IfStem(std::vector<NodePtr> _children, Location _location) :
Node(_children, _location) {}


