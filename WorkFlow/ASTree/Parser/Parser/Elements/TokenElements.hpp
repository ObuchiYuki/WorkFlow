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
    
    // MARK: - Overriable Methods -
    virtual token::TokenType matchType() const = 0;
    
    
    // MARK: - Constructors -
    
    TokenElement() {}
    virtual ~TokenElement(){}
    
    // MARK: - Overrided Methods -
    auto match(Lexer& lexer, int gap) -> bool const override {
        let absIndex = lexer.absIndex(gap);
        try {
            return match_memo.at(absIndex);
        } catch (std::exception e) {
            let a = isMatch(lexer.peek(gap));
            match_memo[absIndex] = a;
            
            rm::debug("[TokenElement<"+ token::TokenTypeDescription(matchType()) +">::match]", "matched:", a ? "true" : "false", "checked: ", lexer.peek(gap)->value);
            
            return a;
        }
    }
    auto parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const override {
        let token = lexer.readNext();
        let leaf = ast::LeafPtr(new T(token, token->location));
        
        res.push_back(leaf);
    }
    auto rstride(Lexer& lexer, int gap) -> int const override {
        return 1;
    }
    
    auto description() -> std::string const override {
        return "[Token " + token::TokenTypeDescription(matchType()) + "]";
    }
private:
    std::unordered_map<int, bool> match_memo;
    
    bool isMatch(token::TokenPtr token) const {
        return matchType() == token->type;
    };
};

class IntegerElement: public TokenElement<ast::IntegerLiteral> {
    token::TokenType matchType() const override {
        return token::TokenType::INTEGER;
    }
};

class StringElement: public TokenElement<ast::StringLiteral> {
    token::TokenType matchType() const override {
        return token::TokenType::STRING;
    }
};

class OperatorElement: public TokenElement<ast::Operator> {
    token::TokenType matchType() const override {
        return token::TokenType::OPERATOR;
    }
};

class IDElement: public TokenElement<ast::Name> {
    token::TokenType matchType() const override {
        return token::TokenType::IDENTIFIER;
    }
};

class DerectiveElement: public TokenElement<ast::Directive> {
    token::TokenType matchType() const override {
        return token::TokenType::DIRECTIVE;
    }
};

}

#endif /* TokenElements_hpp */
