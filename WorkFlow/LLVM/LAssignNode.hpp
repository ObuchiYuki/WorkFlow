//
//  AssignNode.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/16.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef LAssignNode_hpp
#define LAssignNode_hpp

#include <string>
#include <sstream>

#include "LLVMNode.hpp"

namespace wf {namespace llvm{


class AssignNode: public LLVMNode {
private:
    std::string name;
    std::string type;
    std::string value;
public:
    
    AssignNode(std::string _name, std::string _type, std::string _value) :
    name(_name) , type(_type), value(_value) {}
    
    std::string llvmstring() override;
};


}}


#endif /* AssignNode_hpp */
