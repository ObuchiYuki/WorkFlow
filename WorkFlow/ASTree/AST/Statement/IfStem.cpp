//
//  IfStem.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/31.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "IfStem.hpp"

using namespace wf::ast;

auto IfStem::condition()  const -> NodePtr {
    return children[0];
}

auto IfStem::block() const -> NodePtr {
    return children[1];
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

auto IfStem::eval(wf::run::Environment& env) const -> wf::run::Value {
    
    if (condition()->eval(env).boolean()) {
        block()->eval(env);
    }else{
        if (elseBlock()) {
            elseBlock()->eval(env);
        }
    }
    
    return wf::run::Value::voidValue();
}

IfStem::IfStem(std::vector<NodePtr> _children, Location _location) :
Node(_children, _location) {}


