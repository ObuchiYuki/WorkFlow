//
//  Parameter.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/10.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Parameter.hpp"

using namespace wf::ast;

var Parameter::label() const -> std::string {
    return nodeAsLeaf(children[0])->token->value;
}

var Parameter::name() const -> std::string {
    return nodeAsLeaf(children[1])->token->value;
}

var Parameter::description() const -> std::string {
    return "(" + label() + " " + name() + ")";
}
