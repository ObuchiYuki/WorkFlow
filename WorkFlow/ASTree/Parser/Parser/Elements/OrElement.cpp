//
//  OrElement.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Elements.hpp"

#include <exception>
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
    try {
        chooseParser(lexer, gap);
        return true;
    }catch(std::exception e){
        return false;
    }
}

auto OrElement::rstride(Lexer& lexer, int gap) -> int const {
    auto parser = chooseParser(lexer, gap);
    
    return parser->rstride(lexer, gap);
}

auto OrElement::parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const {
    auto parser = chooseParser(lexer, 0);
    
    res.push_back(parser->parse(lexer));
}

auto OrElement::description() -> std::string const{
    return "[Or]";
}

auto OrElement::chooseParser(Lexer& lexer, int index) -> _ParserPtr const {
    int absIndex = lexer.absIndex(index);
    
    try {
        auto parser = matched_parser_memo.at(absIndex);
        return parser;
    } catch (std::exception e) {
        for (let &parser: parsers){
            if (parser->match(lexer, index)){
                matched_parser_memo[absIndex] = parser;
                
                return parser;
            }
        }
        
        throw std::runtime_error("[OrElement::chooseParser] cannot find any matching parser.");
    }
}
