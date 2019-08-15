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

auto ArgumentList::argumentTypes(type::TypeEnvironment &env) const -> std::vector<type::TypePtr> {
    var dec = std::vector<type::TypePtr>();
    for (let& arg: arguments()) {
        
        dec.push_back(arg->returnType(env));
    }
    return dec;
}

auto ArgumentList::arg(int index) const -> std::shared_ptr<Argument> {
    if (numChildren() < index) {
        return nullptr;
    }
    return std::dynamic_pointer_cast<Argument>(children[index]);
}

auto ArgumentList::arguments() const -> rm::vector<std::shared_ptr<Argument>> {
    var vecr = rm::vector<std::shared_ptr<Argument>>();
    for (let& child: children) {
        vecr.push_back(std::dynamic_pointer_cast<Argument>(child));
    }
    
    return vecr;
}

