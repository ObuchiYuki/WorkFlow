//
//  SkipElement.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "ParserElements.hpp"

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

auto SkipElement::match(Lexer& lexer) -> bool const {
    if (skipTokens[0] == "EOL" && lexer.peek(0)->type == wf::token::TokenType::ENDLINE) {
        return true;
    }
    for (let &skipToken: skipTokens) {
        if (lexer.peek(0)->value == skipToken) return true;
    }
    
    return false;
}
auto SkipElement::parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const {
    
    lexer.readNext();               
}
