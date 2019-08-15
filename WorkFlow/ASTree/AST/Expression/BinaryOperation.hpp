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
#include "Expression.hpp"
#include "Type.hpp"

namespace wf { namespace ast {

class BinaryOperation: public Expression {
public:
    auto left() const -> ExpressionPtr;
    auto right() const -> ExpressionPtr;
    
    auto op() const -> type::OperationPtr;
            
    BinaryOperation(std::vector<NodePtr> _children, Location _location) : Expression(_children, _location) {}
    
    var description() const -> std::string override;
    auto eval(wf::run::EnvironmentPtr env) const -> wf::run::Value override;
};

}}

#endif /* BinaryOperation_hpp */
