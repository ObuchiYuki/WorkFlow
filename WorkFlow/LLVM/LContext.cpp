//
//  LContext.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/16.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "LContext.hpp"
#include "rmkit.h"
#include "LLVMNode.hpp"

#include <sstream>

using namespace wf::llvm;

auto Context::llvmstring() -> std::string {
    std::stringstream ss;
    ss << "define" << " " <<  returnType << " " << name;
    if (arguments){
        ss << arguments->llvmstring();
    }else{
        ss << "()";
    }
    ss << "{" << "\n";
    
    for (let& line: body) {
        ss << line->llvmstring();
    }
    
    ss << "\n" << "}";
    
    return ss.str();
}
