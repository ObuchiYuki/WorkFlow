//
//  VarStem.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/04.
//  Copyright © 2019 yuki. All rights reserved.
//

#include <memory>
#include "VarStem.hpp"
#include "Leaf.hpp"

using namespace wf::ast;

var VarStem::valueType() const -> type::TypePtr {
    return init()->returnType();
}

var VarStem::target() const -> std::string {
    
    return nodeAsLeaf(children[0])->token->value;
}

var VarStem::init() const -> ExpressionPtr {
    
    return std::dynamic_pointer_cast<Expression>(children[1]);
}


VarStem::VarStem(std::vector<NodePtr> _children, Location _location) :
Node(_children, _location) {};

var VarStem::description() const -> std::string {
    return "(def " + target() + " = " + init()->description() + ")";
}
