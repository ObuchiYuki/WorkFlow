//
//  ExprElement.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Elements.hpp"

#include <vector>
#include <exception>

#include "Token.hpp"
#include "Parser.hpp"
#include "Lexer.hpp"
#include "BinaryOperation.hpp"

using namespace wf;

// MARK: - Impl -
ExprElement::ExprElement(_ParserPtr exp, Operators map) : ops(map), factor(exp) {};

auto ExprElement::parse(Lexer& lexer, std::vector<NodePtr>& res) const -> void {
    NodePtr right = factor->parse(lexer);
    PrecedencePtr prec = nextOperator(lexer);
    
    while(prec != nullptr) {
        right = doShift(lexer, right, prec->value);
        
        prec = nextOperator(lexer);
    }
    
    res.push_back(right);
}

auto ExprElement::match(Lexer& lexer, int gap) const -> const bool {
    
    return factor->match(lexer, gap);
}

auto ExprElement::rstride(Lexer& lexer, int gap) const -> const int {
    auto rstride = 0;
    auto rgap = gap;
    auto repeatFlag = true;
    
    while (repeatFlag) {
        
        if (factor->match(lexer, rgap)){
            auto a = factor->rstride(lexer, rgap);
            rstride += a;
            rgap += a;
              
        }else if (ops.match(lexer.peek(rgap)->value)){
             rstride += 1;
             rgap += 1;
        }else{
            repeatFlag = false;
        }
    }
    
    return rstride;
}
    
auto ExprElement::description() const -> const std::string{
    return "[Expr]";
}



// MARK: - Private -

PrecedencePtr ExprElement::nextOperator(Lexer& lexer) const  {
    let t = lexer.peek(0);
    
    if (t->type == token::TokenType::OPERATOR) {
        return ops.get(t->value);
    }else{
        return nullptr;
    }
}

bool ExprElement::rightIsExpr(int prec, PrecedencePtr nextPrec) const {
    if (nextPrec->leftAssoc){
        return prec < nextPrec->value;
    } else {
        return prec <= nextPrec->value;
    }
}

NodePtr ExprElement::doShift(Lexer& lexer, NodePtr left, int prec) const{
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
    
