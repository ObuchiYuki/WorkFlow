//
//  BinaryOperation.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Expression_hpp
#define Expression_hpp

#include <memory>

#include "Node.hpp"
#include "Type.hpp"


namespace wf { namespace ast {

class Expression: public Node {
public:
    // MARK: - Constructor -
    Expression(std::vector<NodePtr> _children, Location _location);
    virtual ~Expression(){}
    
    // MARK: - Methods -
            
    var description() const -> std::string override;
    
    virtual var returnType() const -> wf::type::TypePtr;
    
    auto eval(wf::run::EnvironmentPtr env) const -> wf::run::Value override {
        return children[0]->eval(env);
    }
};

typedef std::shared_ptr<Expression> ExpressionPtr;

    
}}

#endif /* BinaryOperation_hpp */
