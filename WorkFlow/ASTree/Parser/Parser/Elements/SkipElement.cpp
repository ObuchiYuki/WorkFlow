//
//  SkipElement.cpp
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

// MARK: - Constructor -
SkipElement::SkipElement(std::string _skipToken) : skipTokens({_skipToken}) {
    
}
SkipElement::SkipElement(std::vector<std::string> _skipTokens) : skipTokens(_skipTokens) {
    
}
// MARK: - Methods -

auto SkipElement::match(Lexer& lexer, int gap) -> bool const {
    
    for (let &skipToken: skipTokens) {
        if (skipToken == "EOL" && lexer.peek(gap)->type == wf::token::TokenType::ENDLINE) {
            return true;
        }
        rm::debug("[SkipElement::match]","matched:", lexer.peek(gap)->value == skipToken ? "true" : "false"
              ,"skipToken: " , skipToken , "check:" , lexer.peek(gap)->value);
        
        if (lexer.peek(gap)->value == skipToken) return true;
    }
    
    return false;
}
auto SkipElement::parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const {
    auto t = lexer.readNext();
    rm::debug("[SkipElement::parse]", "🔥skipped:", t->value);
}

auto SkipElement::rstride(Lexer& lexer, int gap) -> int const {
    return 1;
}

auto SkipElement::description() -> std::string const{
    auto de = std::string("");
    for (let &skipToken: skipTokens) {
        de += "'" + skipToken + "' ";
    }
    
    return de;
}
