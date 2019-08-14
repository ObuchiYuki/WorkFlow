//
//  TypeSpecifier.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/12.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "TypeSpecifier.hpp"
#include "Leaf.hpp"
#include "Type.hpp"

using namespace wf::ast;

var TypeSpecifier::type() const -> TypePtr {
    let name = nodeAsLeaf(children[0])->token->value;
    return TypePtr(new Type(name));
}

