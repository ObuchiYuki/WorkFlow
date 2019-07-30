//
//  ExprElement.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Parser.hpp"

using namespace wf;

// MARK: - Constructor -

ExprElement::ExprElement(_ParserPtr _parser) : factor(_parser) {
    
}

// MARK: - Methods - 
auto ExprElement::parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const {
    let right = factor->parse(lexer);

    res.push_back(right);
}

auto ExprElement::match(Lexer& lexer) -> bool const {
    return factor->match(lexer);
}
