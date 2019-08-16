//
//  Argument.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/16.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "LArgument.hpp"

#include <string>
#include <sstream>

using namespace wf::llvm;

auto Argument::llvmstring() -> std::string {
    std::stringstream ss;
    ss << type << " " << name;
    
    return ss.str();
}
