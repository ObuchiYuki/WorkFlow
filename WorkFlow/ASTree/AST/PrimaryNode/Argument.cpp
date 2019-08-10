//
//  Arguments.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Argument.hpp"


using namespace wf::ast;

var Argument::label() const -> NodePtr {
    if (numChildren() == 2) {
        return children[0];
    }else{
        return nullptr;
    }
}
var Argument::value() const -> NodePtr{
    if (numChildren() == 2) {
        return children[1];
    }else{
        return children[0];
    }
}

auto Argument::eval(wf::run::EnvironmentPtr env) const -> wf::run::Value {
    return value()->eval(env);
}
