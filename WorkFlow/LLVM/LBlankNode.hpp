//
//  LBlankNode.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/16.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef LBlankNode_hpp
#define LBlankNode_hpp

#include "LLVMNode.hpp"

namespace wf {namespace llvm {

class BlankNode: public LLVMNode {
public:
    
    std::string llvmstring() override {
        return "\n";
    }
};

}}

#endif /* LBlankNode_hpp */
