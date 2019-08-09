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

auto Node::eval(wf::run::Environment& env) const -> wf::run::Value {
    rm::debug::warn("[Node] Node with no class must not be evalated. Or you may forget to override eval. This node run all children's eval.");
    for (let &child: children) {
        child->eval(env);
    }
    return wf::run::Value::voidValue();
}


auto Node::description() const -> std::string {
    return "[space]";
}
// MARK: - Leaf - 



Leaf::Leaf(std::shared_ptr<wf::token::Token> _token, Location _location):
Node({}, _location) ,token(_token) {
    
}

auto Leaf::description() const -> std::string {
    return "[Leaf undefined]";
}

auto Leaf::eval(wf::run::Environment& env) const -> wf::run::Value {
    return wf::run::Value(token->value);
}
