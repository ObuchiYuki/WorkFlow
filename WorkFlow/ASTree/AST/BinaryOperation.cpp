//
//  BinaryOperation.cpp
//  WorkFlowa
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "BinaryOperation.hpp"
#include "Leaf.hpp"

using namespace wf::ast;

auto BinaryOperation::right() const -> NodePtr {
    return children[2];
}

auto BinaryOperation::left() const -> NodePtr {
    return children[0];
}

auto BinaryOperation::op() const -> NodePtr {
    return children[1];
}
    
BinaryOperation::BinaryOperation(std::vector<NodePtr> _children, Location _location) :
Node(_children, _location)
{};

auto BinaryOperation::description() const -> std::string {
    return "(" + left()->description() + " " + op()->description() + " " + right()->description() + ")";
}

auto BinaryOperation::eval(wf::run::EnvironmentPtr env) const -> wf::run::Value {
    let op_s = wf::ast::nodeAsLeaf(op())->token->value;
    let lsh = left()->eval(env);
    let rsh = right()->eval(env);

    if (op_s == "<") {
        return wf::run::Value(lsh.integer() < rsh.integer());
    }else if (op_s == ">") {
        return wf::run::Value(lsh.integer() > rsh.integer());
    }else if (op_s == "%") {
        return wf::run::Value(lsh.integer() % rsh.integer());
    }else if (op_s == "+") {
        return wf::run::Value(lsh.integer() + rsh.integer());
    }else if (op_s == "-") {
        return wf::run::Value(lsh.integer() - rsh.integer());
    }else if (op_s == "*") {
        return wf::run::Value(lsh.integer() * rsh.integer());
    }else if (op_s == "/") {
        return wf::run::Value(lsh.integer() / rsh.integer());
    }else if (op_s == "==") {
        return wf::run::Value(lsh.integer() == rsh.integer());
    }
    
    return wf::run::Value::voidValue();
}
