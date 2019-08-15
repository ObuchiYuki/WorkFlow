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

auto BlockStem::description() const -> std::string {
    return "(\n" + rm::description::join(children, ",\n" , [](auto e){return e->description();}) + "\n)";

}
