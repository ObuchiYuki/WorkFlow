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
    const rm::optional<_ParserPtr> _parser = chooseParser(lexer);
    
    if (_parser) {
        let parser = *_parser;
        
        res.push_back(parser->parse(lexer));
    }
}

// MARK: - Private Methods -

auto OrElement::chooseParser(Lexer& lexer, int gap) -> rm::optional<_ParserPtr> const {
    for (let &parser: parsers){
        if (parser->match(lexer, gap)){
            return rm::optional<_ParserPtr>(parser);
        }
    }
    return nil;
}

auto OrElement::rstride(Lexer& lexer, int gap) -> int const {
    let _parser = chooseParser(lexer, gap);
    if (_parser){
        return (*_parser)->rstride(gap);
    }else{
        // TODO: - 直す - 
        throw "Error";
    }
            
}
