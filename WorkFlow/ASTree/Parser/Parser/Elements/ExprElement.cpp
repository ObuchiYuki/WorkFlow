//
//  ExprElement.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Parser.hpp"

using namespace wf;

// MARK: - Constructor -

ExprElement::ExprElement(_ParserPtr _parser, Operators _ops) : factor(_parser) , ops(_ops) {
    
}

// MARK: - Methods - 
auto ExprElement::parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const {
    std::vector<std::vector<NodePtr>> pendings = {};
    while(ops.match(lexer.peek(1)->value)){
        pendings.push_back({factor->parse(lexer), p_operator.parse(lexer)});
        
    }
    
    let u = factor->parse(lexer);
    pendings.back().push_back(u);
    
    let last = pendings.back();
    pendings.pop_back();
    var currentOperation = NodePtr(new ast::BinaryOperation(last, last.back()->location));
    
    while(!pendings.empty()) {
        
        var next = pendings.back();
        pendings.pop_back();
        
        next.push_back(currentOperation);
        currentOperation = NodePtr(new ast::BinaryOperation(next, next.back()->location));
    }
    
    print("Result Opr: ", currentOperation->description());
    res.push_back(currentOperation);
}

auto ExprElement::match(Lexer& lexer) -> bool const {
    return factor->match(lexer);
}
