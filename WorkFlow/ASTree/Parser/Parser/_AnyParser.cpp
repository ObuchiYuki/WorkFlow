//
//  _AnyParser.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//


#include "Parser.hpp"

using namespace wf;

// MARK: - _AnyParser -

auto _AnyParser::parse(Lexer& lexer) -> ast::NodePtr const {
    return _holder->parse(lexer);
}
                
auto _AnyParser::match(Lexer &lexer, int gap) -> bool const {
    return _holder->match(lexer, gap);
}
    
auto _AnyParser::addElement(ElementPtr element) -> void {
    _holder->addElement(element);
}

auto _AnyParser::rstride(Lexer& lexer, int gap) -> int const {
    return _holder->rstride(lexer, gap);
}
