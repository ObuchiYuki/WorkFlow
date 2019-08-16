//
//  LLVMNode.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/16.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef LLVMNode_hpp
#define LLVMNode_hpp

#include <string>
#include <memory>

namespace wf {namespace llvm {

class LLVMNode {
public:
    virtual auto llvmstring() -> std::string = 0;
    
    LLVMNode(){}
    virtual ~LLVMNode() {}
};

typedef std::shared_ptr<LLVMNode> LLVMNodePtr;

}}



#endif /* LLVMNode_hpp */
