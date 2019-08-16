//
//  LArgument.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/16.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef LArgument_hpp
#define LArgument_hpp

#include "LLVMNode.hpp"

#include <string>

namespace wf {namespace llvm {

class Argument: public LLVMNode {
public:
    std::string type;
    std::string name;
    
    auto llvmstring() -> std::string override;
};

}}

#endif /* Argument_hpp */
