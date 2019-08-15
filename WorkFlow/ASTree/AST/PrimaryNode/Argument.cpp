//
//  Arguments.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Argument.hpp"

#include <string>
#include "rmkit.h"

#include "Leaf.hpp"

using namespace wf::ast;

var Argument::label() const -> std::string {
    if (numChildren() == 2) {
        let a = children[0];
        
        
        return nodeAsLeaf(children[0])->token->value;
    }else{
        return "";
    }
}
var Argument::value() const -> NodePtr{
    if (numChildren() == 2) {
        return children[1];
    }else{
        return children[0];
    }
}
