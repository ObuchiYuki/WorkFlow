//
//  ArgumentList.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/16.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef LArgumentList_hpp
#define LArgumentList_hpp

#include <string>
#include <memory>
#include <vector>

#include "LLVMNode.hpp"
#include "LArgument.hpp"

namespace wf {namespace llvm {

class ArgumentList: public LLVMNode {
public:
    std::vector<std::shared_ptr<Argument>> arguments = {};
    
    auto llvmstring() -> std::string override;
    
};

}}

#endif /* ArgumentList_hpp */
