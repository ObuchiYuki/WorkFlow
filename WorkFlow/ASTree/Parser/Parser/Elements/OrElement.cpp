//
//  OrElement.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Elements.hpp"

#include <vector>

#include "rmkit.h"
#include "Parser.hpp"
#include "Lexer.hpp"

using namespace wf;

// MARK: - Constructor -
OrElement::OrElement(std::vector<_ParserPtr> _parsers): parsers(_parsers) {
    
}

// MARK: - Methods -
auto OrElement::match(Lexer& lexer, int gap) -> bool const {
    
    for (let &parser: parsers){
        if (parser->match(lexer, gap)){
            return true;
        }
    }
          
    return false;
}

auto OrElement::parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const {
    for (let &parser: parsers){
        if (parser->match(lexer, 0)){
            res.push_back(parser->parse(lexer));
        }
    }
    
}

// MARK: - Private Methods -

auto OrElement::rstride(Lexer& lexer, int gap) -> int const {
    for (let &parser: parsers){
        if (parser->match(lexer, gap)){
            return parser->rstride(lexer, gap);
        }
    }
    
    // TODO: - 直す -
    throw "Error";
}
