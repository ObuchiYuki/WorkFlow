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

class BinaryOperator: public Node {
public:
    auto right() -> NodePtr;
    auto left() -> NodePtr;
    
    auto op() -> NodePtr;
            
    BinaryOperator(std::vector<NodePtr> _children, Location _location);
};

}}

#endif /* BinaryOperation_hpp */
