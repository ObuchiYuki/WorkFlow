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
    var left() const -> ExpressionPtr;
    var right() const -> ExpressionPtr;
    
    var op(wf::type::TypeEnvironment& env) const -> type::FunctionTypePtr;
    
    var returnType(wf::type::TypeEnvironment& env) const -> wf::type::TypePtr override {
        return op(env)->returnType;
    }
            
    BinaryOperation(std::vector<NodePtr> _children, Location _location) : Expression(_children, _location) {}
    
    var description() const -> std::string override;
};

}}

#endif /* BinaryOperation_hpp */
