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
    rm::debug("------------------------ OR match Start ------------------------");
    try {
        chooseParser(lexer, gap);
        rm::debug("------------------------ OR match End ------------------------");
        return true;
    }catch(std::exception e){
        rm::debug("------------------------ OR match End ------------------------");
        return false;
    }
    
}

auto OrElement::parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const {
    rm::debug("------------------------ OR parse Start ------------------------");
    rm::debug("[OrElement::parse] parsers.size", parsers.size());

    auto parser = chooseParser(lexer, 0);
    
    rm::debug("[OrElement::parse]", "⭕️ matched:", lexer.peek(0)->value, ",match:", parser->description());
    
    res.push_back(parser->parse(lexer));
    
    rm::debug("------------------------ OR parse End ------------------------");
}

// MARK: - Private Methods -

auto OrElement::rstride(Lexer& lexer, int gap) -> int const {
    rm::debug("------------------------ OR rstride Start ------------------------");
    auto parser = chooseParser(lexer, gap);
    rm::debug("------------------------ OR rstride End ------------------------");
    return parser->rstride(lexer, gap);
    
}

auto OrElement::description() -> std::string const{
    return "[Or]";
}

auto OrElement::chooseParser(Lexer& lexer, int index) -> _ParserPtr const {
    int absIndex = lexer.absIndex(index);
    
    rm::debug("[OrElement::chooseParser]", "peek(",absIndex,"):", lexer.peek(index)->value);
    try {
        auto parser = matched_parser_memo.at(absIndex);
        return parser;
    } catch (std::exception e) {
        for (let &parser: parsers){
            if (parser->match(lexer, index)){
                matched_parser_memo[absIndex] = parser;
                
                rm::debug("[OrElement::chooseParser]", "NEW", "peek(",absIndex,"):", lexer.peek(absIndex)->value, "parser:" ,parser->description());
                return parser;
            }
        }
        
        throw std::runtime_error("[OrElement::chooseParser] cannot find any matching parser.");
    }
}
