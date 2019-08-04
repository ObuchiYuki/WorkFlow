//
//  BinaryOperation.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef BinaryOperation_hpp
#define BinaryOperation_hpp

#include "Node.hpp"

namespace wf { namespace ast {

class BinaryOperation: public Node {
public:
    auto left() -> NodePtr;
    auto right() -> NodePtr;
    
    auto op() -> NodePtr;
            
    BinaryOperation(std::vector<NodePtr> _children, Location _location);
    
    const std::string description() override;
    wf::run::Value eval(wf::run::Environment& env) override;
};

}}

#endif /* BinaryOperation_hpp */
