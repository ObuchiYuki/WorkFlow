//
//  BinaryOperation.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Expression_hpp
#define Expression_hpp

#include "Node.hpp"

namespace wf { namespace ast {

class Expression: public Node {
public:
    virtual ~Expression(){}
    
    Expression(std::vector<NodePtr> _children, Location _location);
            
    auto description() -> std::string const override;
    
};

class BinaryOperation: public Expression {
public:
    auto right() -> NodePtr;
    auto left() -> NodePtr;
    
    auto op() -> NodePtr;
            
    BinaryOperation(std::vector<NodePtr> _children, Location _location);
    
    auto description() -> std::string const override;
};

    
class NegativeExpr: public Expression {
public:
    NegativeExpr(std::vector<NodePtr> _children, Location _location);
    
    auto description() -> std::string const override;
};
    
}}

#endif /* BinaryOperation_hpp */
