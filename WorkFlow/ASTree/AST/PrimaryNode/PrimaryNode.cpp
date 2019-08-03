//
//  PrimaryNode.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "PrimaryNode.hpp"

using namespace wf::ast;

// MARK: - Impl

auto PrimaryNode::child() -> LeafPtr const{
    
    return std::dynamic_pointer_cast<Leaf>(children[0]);
};

PrimaryNode::PrimaryNode(std::vector<NodePtr> _children, Location _location) :
Node(_children, _location) {};

PrimaryNode::~PrimaryNode(){};

auto PrimaryNode::description() -> std::string const {
    return children[0]->description();
}
