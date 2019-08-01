//
//  OrElement.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "../Parser.hpp"

using namespace wf;

// MARK: - Constructor -
OrElement::OrElement(std::vector<_ParserPtr> _parsers): parsers(_parsers) {
    
}

// MARK: - Methods -
auto OrElement::match(Lexer& lexer) -> bool const {
    guard_let_else(parser, chooseParser(lexer), false);
                          
    return true;
}

auto OrElement::parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const {
    guard_let(parser, chooseParser(lexer));
                          
    res.push_back(parser->parse(lexer));
                   
}

// MARK: - Private Methods -

auto OrElement::chooseParser(Lexer& lexer) -> optinal<_ParserPtr> const {
    for (let &parser: parsers){
        if (parser->match(lexer)){
            return optinal<_ParserPtr>(parser);
        }
    }
    return nil(_ParserPtr);
}
