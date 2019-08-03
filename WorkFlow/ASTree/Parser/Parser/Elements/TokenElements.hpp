//
//  TokenElements.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/03.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef TokenElements_hpp
#define TokenElements_hpp

#include "Elements.hpp"

namespace wf {

/// Expresses leaf token like number, string ...
template<class T>
class TokenElement: public Element {
public:
    virtual bool isMatch(token::TokenPtr token) const = 0 ;
    
    TokenElement() {}
    virtual ~TokenElement(){}
    
    auto match(Lexer& lexer) -> bool const override {
        return isMatch(lexer.peek(0));
    }
    auto parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const override {
        let token = lexer.readNext();
        let leaf = ast::LeafPtr(new T(token, token->location));
        
        res.push_back(leaf);
    }
};

class IntegerElement: public TokenElement<ast::IntegerLiteral> {
    bool isMatch(token::TokenPtr token) const override {
        return token->type == token::TokenType::INTEGER;
    }
};

class StringElement: public TokenElement<ast::StringLiteral> {
    bool isMatch(token::TokenPtr token) const override {
        return token->type == token::TokenType::STRING;
    }
};

class OperatorElement: public TokenElement<ast::Operator> {
    bool isMatch(token::TokenPtr token) const override {
        return token->type == token::TokenType::OPERATOR;
    }
};

class IDElement: public TokenElement<ast::Name> {
    bool isMatch(token::TokenPtr token) const override {
        return token->type == token::TokenType::IDENTIFIER;
    }
};

class DerectiveElement: public TokenElement<ast::Directive> {
    bool isMatch(token::TokenPtr token) const override {
        return token->type == token::TokenType::DIRECTIVE;
    }
};

}

#endif /* TokenElements_hpp */
