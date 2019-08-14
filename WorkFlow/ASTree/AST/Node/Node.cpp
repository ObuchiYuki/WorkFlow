//
//  Node.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Node.hpp"

using namespace wf::ast;

// MARK: - Node -

Node::Node(std::vector<std::shared_ptr<Node>> _children, Location _location):
children(_children), location(_location){
    
}
void Node::appendChild(std::shared_ptr<Node> child) {
    children.push_back(child);
}

int Node::numChildren() const {
    return static_cast<int>(children.size());
}

auto Node::eval(wf::run::EnvironmentPtr env) const -> wf::run::Value {
    rm::debug::warn("[Node] Node with no class must not be evalated. Or you may forget to override eval. This node first children's eval.");
    
    return children[0]->eval(env);
}

var Node::llvm() const -> std::string {
    rm::debug::warn("[Node::description] Node with no class have no LLVM. Or you may forget to override llvm. This node return comment.");
    
    return "; Node with no class. Something Wrong...";
}

auto Node::description() const -> std::string {
    rm::debug::warn("[Node::description] Node with no class have no description. Or you may forget to override description. This node returns [node].");
    return "[node]";
}
// MARK: - Leaf - 


