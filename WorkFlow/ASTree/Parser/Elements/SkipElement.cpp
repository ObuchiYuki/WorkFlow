//
//  SkipElement.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "../Parser.hpp"

using namespace wf;

// MARK: - Constructor -
SkipElement::SkipElement(std::string _skipToken) : skipToken(_skipToken) {
    
}
// MARK: - Methods -

auto SkipElement::match(Lexer& lexer) -> bool const {
    
    return lexer.peek(0)->value == skipToken;
}
auto SkipElement::parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const {
    
    lexer.readNext();               
}
