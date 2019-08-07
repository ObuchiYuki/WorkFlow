//
//  TreeElement.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "TreeElement.hpp"

#include <vector>

#include "Parser.hpp"
#include "Lexer.hpp"


using namespace wf;

// MARK: - Constructor -
TreeElement::TreeElement(_ParserPtr _parser): parser(_parser) {
    
}

// MARK: - Methods -

auto TreeElement::match(Lexer& lexer, int gap) const -> bool const {
    
    return parser->match(lexer, gap);
}

auto TreeElement::parse(Lexer& lexer, std::vector<NodePtr> &res) const -> void {
                   
    res.push_back(parser->parse(lexer));
}

auto TreeElement::rstride(Lexer& lexer, int gap) const -> int const {
    
    return parser->rstride(lexer, gap);
}

auto TreeElement::description() const -> const std::string{
    return "[Tree]";
}
