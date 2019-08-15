//
//  Type.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/14.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Type.hpp"

using namespace wf::type;

auto Type::isChildrenOf(Type type) const -> bool {
    if (parent == nullptr) {return false;} // null チェック
    
    if (*parent == type) {
        return true;
    }else{
        return parent->isChildrenOf(type);
    }
}

auto Type::registerType(TypePtr type) {
    types.push_back(type);
}

auto Type::registerProperty(PropertyPtr prop) {
    properties.push_back(prop);
}

auto Type::registerMethod(MethodPtr method) {
    methods.push_back(method);
}


auto Type::searchOperation(std::string name, TypePtr left, TypePtr right) -> OperationPtr {
    for (let& method: methods) {
        let opr = std::dynamic_pointer_cast<Operation>(method);
        if  (opr != nullptr && opr->name == name && opr->left() == left && opr->right() == right) {
            return opr;
        }
    }
    return nullptr;
}


TypePtr Type::global = TypePtr(new Type("__global"));
