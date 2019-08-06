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
    rm::dprint("------------------------ OR match Start ------------------------");
    try {
        chooseParser(lexer, gap);
        rm::dprint("------------------------ OR match End ------------------------");
        return true;
    }catch(std::exception e){
        rm::dprint("------------------------ OR match End ------------------------");
        return false;
    }
    
}

auto OrElement::parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const {
    rm::dprint("------------------------ OR parse Start ------------------------");

    auto parser = chooseParser(lexer, lexer.index);
    
    rm::dprint("[OrElement::parse]", "⭕️ matched:", lexer.peek(0)->value, ",match:", parser->description());
    
    res.push_back(parser->parse(lexer));
    
    rm::dprint("------------------------ OR parse End ------------------------");
}

// MARK: - Private Methods -

auto OrElement::rstride(Lexer& lexer, int gap) -> int const {
    rm::dprint("------------------------ OR rstride Start ------------------------");
    auto parser = chooseParser(lexer, gap);
    rm::dprint("------------------------ OR rstride End ------------------------");
    return parser->rstride(lexer, gap);
    
}

auto OrElement::description() -> std::string const{
    return "[Or]";
}

auto OrElement::chooseParser(Lexer& lexer, int index) -> _ParserPtr const {
    rm::dprint("[OrElement::chooseParser]", "peek(",index,"):", lexer.peek(index)->value);
    try {
        auto parser = matched_parser_memo.at(index);
        rm::dprint("[OrElement::chooseParser]", "ALREADY");
        return parser;
    } catch (std::exception e) {
        for (let &parser: parsers){
            if (parser->match(lexer, index)){
                matched_parser_memo[index] = parser;
                print("[OrElement::chooseParser]", "NEW");
                return parser;
            }
        }
        
        throw std::runtime_error("[OrElement::chooseParser] cannot find any matching parser.");
    }
}
