//
//  BlockStem.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/01.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Statement.hpp"
#include <sstream>

using namespace wf::ast;

BlockStem::BlockStem(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {};

auto BlockStem::description() -> std::string const {
    var sstr = std::stringstream();
    
    sstr << "(";
    
    for (let &statement: children){
        sstr << statement->children[0]->children[0]->description();
        sstr << " ";
    }
    
    sstr << ")";
    
    return sstr.str();
}
