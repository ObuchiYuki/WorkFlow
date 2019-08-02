//
//  OrElement.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "../Parser.hpp"

#include <vector>

using namespace wf;

// MARK: - Constructor -
OrElement::OrElement(std::vector<_ParserPtr> _parsers): parsers(_parsers) {
    
}

// MARK: - Methods -
auto OrElement::match(Lexer& lexer) -> bool const {
    
    return chooseParser(lexer) != nil;
}

auto OrElement::parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const {
    const rm::optional<_ParserPtr> _parser = chooseParser(lexer);
    
    if (_parser) {
        let parser = *_parser;
        
        res.push_back(parser->parse(lexer));
    }
}

// MARK: - Private Methods -

auto OrElement::chooseParser(Lexer& lexer) -> rm::optional<_ParserPtr> const {
    for (let &parser: parsers){
        if (parser->match(lexer)){
            return rm::optional<_ParserPtr>(parser);
        }
    }
    return nil;
}
