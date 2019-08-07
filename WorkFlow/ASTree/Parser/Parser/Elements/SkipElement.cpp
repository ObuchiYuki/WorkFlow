//
//  SkipElement.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "SkipElement.hpp"

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

auto SkipElement::match(Lexer& lexer, int gap) const -> bool const {
    
    for (let &skipToken: skipTokens) {
        if (skipToken == "EOL" && lexer.peek(gap)->type == wf::token::TokenType::ENDLINE) {
            return true;
        }
        
        if (lexer.peek(gap)->value == skipToken) return true;
    }
    
    return false;
}
auto SkipElement::parse(Lexer& lexer, std::vector<ast::NodePtr> &res) const -> void {
    
    auto t = lexer.readNext();
}

auto SkipElement::rstride(Lexer& lexer, int gap) const -> int const {
    return 1;
}

auto SkipElement::description() const -> const std::string{
    auto de = std::string("");
    for (let &skipToken: skipTokens) {
        de += "'" + skipToken + "' ";
    }
    
    return de;
}
