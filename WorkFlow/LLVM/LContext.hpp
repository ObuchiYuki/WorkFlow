//
//  Context.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/16.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef LContext_hpp
#define LContext_hpp

#include "LLVMNode.hpp"
#include "rmkit.h"

#include <string>
#include <memory>

#include "LArgumentList.hpp"
#include "LAssignNode.hpp"
#include "LBlankNode.hpp"
#include "LAddNode.hpp"

namespace wf {namespace llvm {

class Context: public LLVMNode {
public:
    // MARK: - Properties -
    
    std::string name;
    std::string returnType;

    std::shared_ptr<ArgumentList> arguments = {};
    std::vector<LLVMNodePtr> body;
    
    // MARK: - Methods -
    
    auto assign(std::string name, std::string type, std::string value) {
        let e_pt = LLVMNodePtr(new AssignNode(name, type, value));
        
        body.push_back(e_pt);
    }
    
    auto blank() {
        let e_pt = LLVMNodePtr(new BlankNode());
        
        body.push_back(e_pt);
    }
    
    auto add(std::string result, std::string rtype, std::string first, std::string second) {
        let e_pt = LLVMNodePtr(new AddNode(result, rtype, first, second));
        
        body.push_back(e_pt);
    }
    
    
    auto llvmstring() -> std::string override;
    
    Context(std::string _name, std::string _returnType) : name(_name), returnType(_returnType) {}
    
};



}}

#endif /* Context_hpp */
