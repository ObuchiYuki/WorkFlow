//
//  BlockStem.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/01.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "BlockStem.hpp"
#include <sstream>


using namespace wf::ast;

BlockStem::BlockStem(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {};

auto BlockStem::eval(wf::run::Environment &env) const -> wf::run::Value {
    for (let &child: children){
        child->eval(env);
    }
    
    return wf::run::Value::voidValue();
}

auto BlockStem::description() const -> std::string {
    var sstr = std::stringstream();
    
    sstr << "(";
    
    for (let &statement: children){
        sstr << statement->description();
        sstr << " ";
    }
    
    sstr << ")";
    
    return sstr.str();
}
