
//
//  RepeatElement.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Elements.hpp"

#include <vector>

#include "Parser.hpp"
#include "Lexer.hpp"


using namespace wf;

// MARK: - Constructor -
RepeatElement::RepeatElement(_ParserPtr _parser, bool _once) : parser(_parser), isOptional(_once) {
    
}

// MARK: - Methods -
auto RepeatElement::rstride(Lexer& lexer, int gap) -> int const {
    let absIndex = lexer.absIndex(gap);
    try {
        return rstride_memo.at(absIndex);
    }catch(std::exception e){}
    
    var rgap = gap;
    var rstride = 0;
    
    
    rm::debug("------------------------ Repeat rstride Start ------------------------");
    while(parser->match(lexer, rgap)) {
        let a = parser->rstride(lexer, rgap);
        rstride += a;
        rgap += a;
        
        if (isOptional) break;
    }
    rm::debug("------------------------ Repeat rstride End ------------------------");
    
    rstride_memo[absIndex] = rstride;
    return rstride;
}

auto RepeatElement::match(Lexer& lexer, int gap) -> bool const {
    if (isOptional) return true;
    
    auto asbIndex = lexer.absIndex(gap);
    
    try {
        return match_memo.at(asbIndex);
        
    } catch (std::exception e) {
        let a = parser->match(lexer, gap);
        
        match_memo[asbIndex] = a;
        return a;
    }
}

auto RepeatElement::parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const {
    
    rm::debug("------------------------ Repeat parse Start ------------------------");
    while (parser->match(lexer, 0)) {
        let node = parser->parse(lexer);
        
        if (node->numChildren() > 0) res.push_back(node);
        if (isOptional) break;
    }
    
    rm::debug("------------------------ Repeat parse End ------------------------");
}


auto RepeatElement::description() -> std::string const{
    return "[Repeat " + parser->description() + "]";
}














