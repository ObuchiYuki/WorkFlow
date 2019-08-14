//
//  TokenElements.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/03.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef TokenElements_hpp
#define TokenElements_hpp

#include <string>

#include "Elements.hpp"
#include "rmkit.h"


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
    
    var isEdgeParser() const -> bool override {return true;}
    
    auto match(Lexer& lexer, int gap) const -> bool const override {
        
        return isMatch(lexer.peek(gap));
    }
    auto rstride(Lexer& lexer, int gap) const -> int const override {
        
        return 1;
    }
    
    auto parse(Lexer& lexer, std::vector<ast::NodePtr> &res) const -> void override {
        let token = lexer.readNext();
        let leaf = ast::LeafPtr(new T(token, token->location));
        
        res.push_back(leaf);
    }
    
    auto description() const -> const std::string override {
        return "[Token " + token::TokenTypeDescription(matchType()) + "]";
    }
private:
    
    virtual bool isMatch(token::TokenPtr token) const {
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

static rm::vector<std::string> __reservedWords;

class IDElement: public TokenElement<ast::Name> {
public:
    static auto addReservedWord(std::string word) {
        __reservedWords.push_back(word);
    }
    
    auto isMatch(token::TokenPtr token) const -> bool override {
        return (token->type == token::TokenType::IDENTIFIER && !__reservedWords.contains(token->value));
        
    };
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
