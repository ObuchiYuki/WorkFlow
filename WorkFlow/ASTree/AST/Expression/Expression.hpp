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
    
    virtual auto eval(wf::run::Environment env) -> Value override {
        return children[0]->eval(env);
    }
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

class Calling: public Expression {
public:
    auto target() -> NodePtr;
    auto args() -> NodePtr;
    
    Calling(std::vector<NodePtr> _children, Location _location);
        
    auto description() -> std::string const override;
    
    virtual auto eval(wf::run::Environment env) -> Value override {
        
        let leaf = std::dynamic_pointer_cast<Leaf>(target());
        
        if (leaf) {
            let name = leaf->token->value;
            if (name == "print") {
                
                print(args()->eval(env));
            }
        }
        
        return Value();
    }
};
    
}}

#endif /* BinaryOperation_hpp */
