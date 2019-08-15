//
//  Node.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Node.hpp"
#include "WorkFlowError.hpp"

using namespace wf::ast;

// MARK: - Node -

Node::Node(std::vector<std::shared_ptr<Node>> _children, Location _location):
children(_children), location(_location){
    
}
void Node::appendChild(std::shared_ptr<Node> child) {
    children.push_back(child);
}

auto Node::typeRegister(type::TypePtr type) -> void {
    throw WorkFlowError("Node::typeRegister: Node with no class cannnot register any types.");
}

auto Node::typeCheck(type::TypeEnvironment& env) -> void{
    for (let& child : children) {
        child->typeCheck(env);
    }
}

auto Node::eval(wf::run::EnvironmentPtr env) -> wf::run::Value {
    throw WorkFlowError("Node::eval: Node with no class cannot be evalated. Or you may forget to override Node::eval.");
}


int Node::numChildren() const {
    return static_cast<int>(children.size());
}

auto Node::description() const -> std::string {
    rm::debug::warn("[Node::description] Node with no class have no description. Or you may forget to override description. This node returns [node].");
    return "[node]";
}
// MARK: - Leaf - 


