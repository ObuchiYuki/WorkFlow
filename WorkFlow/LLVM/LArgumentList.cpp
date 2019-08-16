//
//  ArgumentList.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/16.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "LArgumentList.hpp"

#include <sstream>

using namespace wf::llvm;

auto ArgumentList::llvmstring() -> std::string {
    std::stringstream ss;
    if (arguments.empty()) {
        ss << "()";
    }
    ss << std::string("(") << arguments.front()->llvmstring();
    
    for (decltype(arguments.size()) i = 1; i < arguments.size(); ++i) {
        ss << std::string(", ") << arguments[i]->llvmstring();
    }
    ss << std::string(")");
    
    return ss.str();
}
