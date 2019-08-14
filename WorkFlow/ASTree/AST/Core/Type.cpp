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

rm::vector<TypePtr> Type::_registeredType = {};

TypePtr Type::Int =          TypePtr(new Type("Int"));
TypePtr Type::String =       TypePtr(new Type("String"));
TypePtr Type::Array =        TypePtr(new Type("Array"));
TypePtr Type::Dictionary =   TypePtr(new Type("Dictionary"));
TypePtr Type::Float =        TypePtr(new Type("Float"));
