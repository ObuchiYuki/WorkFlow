//
//  AssignNode.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/16.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "LAssignNode.hpp"

#include <string>
#include <sstream>

using namespace wf::llvm;

std::string AssignNode::llvmstring() {
    std::stringstream ss;
    
    ss << name << "_p" << " = " << "alloca " << type;
    ss << "\n";
    ss << "store " << type << " " << value << ", " << type << "* " << name << "_p";
    ss << "\n";
    ss << name << " = " << "load " << type << ", " << type << "* " << name << "_p";
    ss << "\n";
    
    return ss.str();
}
