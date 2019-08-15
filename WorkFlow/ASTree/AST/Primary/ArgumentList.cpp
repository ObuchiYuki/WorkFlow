//
//  ArgumentList.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "ArgumentList.hpp"

#include <memory>
#include <vector>
#include <string>

#include "WorkFlowError.hpp"
#include "Argument.hpp"


using namespace wf::ast;

var ArgumentList::numArgument() const -> int{
    return numChildren();
}
auto ArgumentList::arg(int index) const -> std::shared_ptr<Argument> {
    if (numChildren() < index) {
        return nullptr;
    }
    return std::dynamic_pointer_cast<Argument>(children[index]);
}

auto ArgumentList::arguments() const -> std::vector<std::shared_ptr<Argument>> {
    var vecr = std::vector<std::shared_ptr<Argument>>();
    for (let& child: children) {
        vecr.push_back(std::dynamic_pointer_cast<Argument>(child));
    }
    
    return vecr;
}

