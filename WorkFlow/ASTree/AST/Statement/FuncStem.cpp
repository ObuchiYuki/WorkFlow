//
//  FuncStem.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/08.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "FuncStem.hpp"

using namespace wf::ast;

var FuncStem::name() const -> std::string {
    
    return nodeAsLeaf(children[0])->token->value;
}
var FuncStem::parameters() const -> NodePtr {
    
    return children[1];
}
var FuncStem::body() const -> NodePtr {
    return children[2];
}

auto FuncStem::eval(wf::run::Environment& env)  const-> wf::run::Value {
    env.set(name(), wf::run::Value(body()));
    
    return wf::run::Value::voidValue();
}
