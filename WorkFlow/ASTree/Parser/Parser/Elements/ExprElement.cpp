//
//  ExprElement.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Elements.hpp"

#include <vector>

#include "Token.hpp"
#include "Parser.hpp"
#include "Lexer.hpp"

using namespace wf;

// MARK: - Impl -
ExprElement::ExprElement(_ParserPtr exp, Operators map) : ops(map), factor(exp) {};

auto ExprElement::parse(Lexer& lexer, std::vector<NodePtr>& res) -> void const {
    NodePtr right = factor->parse(lexer);
    PrecedencePtr prec = nextOperator(lexer);
    
    while(prec != nullptr) {
        right = doShift(lexer, right, prec->value);
        
        prec = nextOperator(lexer);
    }
    
    res.push_back(right);
}

auto ExprElement::match(Lexer& lexer) -> bool const {
    return factor->match(lexer);
}

// MARK: - Private -

PrecedencePtr ExprElement::nextOperator(Lexer& lexer) {
    let t = lexer.peek(0);
    
    if (t->type == token::TokenType::OPERATOR) {
        return ops.get(t->value);
    }else{
        return nullptr;
    }
}

bool ExprElement::rightIsExpr(int prec, PrecedencePtr nextPrec) {
    if (nextPrec->leftAssoc){
        return prec < nextPrec->value;
    } else {
        return prec <= nextPrec->value;
    }
}

NodePtr ExprElement::doShift(Lexer& lexer, NodePtr left, int prec) {
    var list = std::vector<NodePtr>();
    
    list.push_back(left);
    let token = lexer.readNext();
    list.push_back(NodePtr(new ast::Operator(token, token->location)));
    
    NodePtr right = factor->parse(lexer);
    
    PrecedencePtr next = nextOperator(lexer);
    
    while (next != nullptr && rightIsExpr(prec, next)) {
        right = doShift(lexer, right, next->value);
        
        next = nextOperator(lexer);
    }
    
    list.push_back(right);
    
    return NodePtr(new ast::BinaryOperation(list, list.front()->location));
}
    

    
    
    
    
    


// MARK: - Constructor -


