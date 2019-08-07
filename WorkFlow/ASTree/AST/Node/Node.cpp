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

int Node::numChildren() {
    return static_cast<int>(children.size());
}

auto Node::eval(wf::run::Environment& env) -> wf::run::Value {
    rm::warn("[Node] Node with no class must not be evalated. This node run all children's eval.");
    for (let &child: children) {
        child->eval(env);
    }
    return wf::run::Value::voidValue();
}


auto Node::description() -> std::string const{
    return "[space]";
}
// MARK: - Leaf - 



Leaf::Leaf(std::shared_ptr<wf::token::Token> _token, Location _location):
Node({}, _location) ,token(_token) {
    
}

auto Leaf::description() -> std::string const {
    return "[Leaf undefined]";
}

auto Leaf::eval(wf::run::Environment& env) -> wf::run::Value {
    return wf::run::Value(token->value);
}
