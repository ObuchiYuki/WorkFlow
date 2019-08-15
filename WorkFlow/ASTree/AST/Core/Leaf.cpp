//
//  Leaf.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Leaf.hpp"

using namespace wf::ast;

Leaf::Leaf(std::shared_ptr<wf::token::Token> _token, Location _location):
Node({}, _location) ,token(_token) {
    
}

auto Leaf::description() const -> std::string {
    return "[Leaf undefined]";
}
