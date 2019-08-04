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
    
    virtual auto eval(wf::run::Environment& env) -> wf::run::Value override {
        return children[0]->eval(env);
    }
};
    
}}

#endif /* BinaryOperation_hpp */
