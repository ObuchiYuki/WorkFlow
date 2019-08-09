//
//  ArgumentList.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "ArgumentList.hpp"
#include "WorkFlowError.hpp"

using namespace wf::ast;

var ArgumentList::numArgument() const -> int{
    return numChildren();
}
auto ArgumentList::arg(int index) const -> NodePtr {
    if (numChildren() < index) {
        return nullptr;
    }
    return children[index];
}


auto ArgumentList::eval(wf::run::Environment& env) const -> wf::run::Value {
    throw wf::WorkFlowError("ArgumentList must not be evalated. Something is wrong.");
}

