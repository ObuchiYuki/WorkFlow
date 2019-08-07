//
//  TreeElement.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Elements.hpp"

#include <vector>

#include "Parser.hpp"
#include "Lexer.hpp"


using namespace wf;

// MARK: - Constructor -
TreeElement::TreeElement(_ParserPtr _parser): parser(_parser) {
    
}

// MARK: - Methods -

auto TreeElement::match(Lexer& lexer, int gap) -> bool const {
    
    return parser->match(lexer, gap);
}

auto TreeElement::parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const {
                   
    res.push_back(parser->parse(lexer));
}

auto TreeElement::rstride(Lexer& lexer, int gap) -> int const {
    
    return parser->rstride(lexer, gap);
}

auto TreeElement::description() -> std::string const{
    return "[Tree]";
}
