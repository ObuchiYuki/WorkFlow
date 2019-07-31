//
//  PrimaryParsers.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Parser.hpp"

using namespace wf;

// MARK: - Methods -
template<class T>
auto _PrimaryParser<T>::match(Lexer& lexer) -> bool const {
                
    return isMatch(lexer.peek(0));
}

template<class T>
auto _PrimaryParser<T>::parse(Lexer& lexer) -> std::shared_ptr<T> const {
    let token = lexer.readNext();
                        
    let value = NodePtr(new wf::ast::Leaf(token, token->location));
    return std::shared_ptr<T>(new T({value}, token->location));

}

// MARK: - Primary Parser Impls -


auto IdentifierParser::isMatch(TokenPtr token) -> bool const {
    
    return token->type == wf::token::TokenType::IDENTIFIER;
}
auto StringParser::isMatch(TokenPtr token) -> bool const {
    
    return token->type == wf::token::TokenType::STRING;
}
auto IntegerParser::isMatch(TokenPtr token) -> bool const {
    
    return token->type == wf::token::TokenType::INTEGER;
}
auto DirectiveParser::isMatch(TokenPtr token) -> bool const {
    
    return token->type == wf::token::TokenType::DIRECTIVE;
}
auto FloatParser::isMatch(TokenPtr token) -> bool const {
    
    return token->type == wf::token::TokenType::FLOAT;
}
auto OperatorParser::isMatch(TokenPtr token) -> bool const {
    
    if (token->type != wf::token::TokenType::IDENTIFIER) return false;
            
    for (let &i: {"|>", "+", "-", "*", "/", "<", ">", "<=", ">=", "=="}) {
                
        if (i == token->value) {
            return true;
        }
    }
            
    return false;
}

auto EOLParser::isMatch(TokenPtr token) -> bool const {
    return token->type == wf::token::TokenType::ENDLINE;
}
