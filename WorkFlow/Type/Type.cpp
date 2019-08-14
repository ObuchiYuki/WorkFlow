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
