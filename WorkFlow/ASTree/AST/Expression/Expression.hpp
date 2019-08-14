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
#include "Type.hpp"


namespace wf { namespace ast {

class Expression: public Node {
public:
    // MARK: - Constructor -
    Expression(std::vector<NodePtr> _children, Location _location);
    virtual ~Expression(){}
    
    // MARK: - Methods -
            
    var description() const -> std::string override;
    virtual var returnTyep() const -> wf::ast::TypePtr;
    
    auto eval(wf::run::EnvironmentPtr env) const -> wf::run::Value override {
        return children[0]->eval(env);
    }
};
    
}}

#endif /* BinaryOperation_hpp */
