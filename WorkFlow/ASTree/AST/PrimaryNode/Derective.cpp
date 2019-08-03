//
//  DerectiveLiteral.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "PrimaryNode.hpp"


using namespace wf::ast;

auto Directive::value() -> std::string const {
                
    return child()->token->value;
}

Directive::Directive(std::vector<NodePtr> _children, Location _location) :
PrimaryNode(_children, _location)
{}

auto Directive::description() -> std::string const{
    return "@" + child()->token->value;
}
