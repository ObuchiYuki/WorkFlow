//
//  LAddNode.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/16.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "LAddNode.hpp"

#include <sstream>

using namespace wf::llvm;

std::string AddNode::llvmstring() {
    std::stringstream ss;
    
    ss << result << " = ";
    ss << "add" << " " << rtype << " " << first << " " << second;
    
    return ss.str();
}
