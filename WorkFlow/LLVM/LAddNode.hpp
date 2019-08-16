//
//  LAddNode.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/16.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef LAddNode_hpp
#define LAddNode_hpp

#include "LLVMNode.hpp"

namespace wf {namespace llvm {

class AddNode: public LLVMNode {
private:
    std::string result;
    std::string rtype;
    std::string first;
    std::string second;
    
public:
    AddNode(std::string _result, std::string _rtype, std::string _first, std::string _second) :
    result(_result), rtype(_rtype), first(_first), second(_second) {}
        
    
    std::string llvmstring() override;
};

}}

#endif /* LAddNode_hpp */
