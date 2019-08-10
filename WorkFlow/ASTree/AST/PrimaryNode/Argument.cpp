//
//  Arguments.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Argument.hpp"


using namespace wf::ast;


var Argument::value() const -> NodePtr{
    return children[0];
}
auto Argument::eval(wf::run::EnvironmentPtr env) const -> wf::run::Value {
    return children[0]->eval(env);
}
