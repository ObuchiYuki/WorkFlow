//
//  TreeElement.cpp
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
TreeElement::TreeElement(_ParserPtr _parser): parser(_parser) {
    
}

// MARK: - Methods -

auto TreeElement::match(Lexer& lexer, int gap) -> bool const {
    let absIndex = lexer.absIndex(gap);
    try {
        return match_memo.at(absIndex);
    } catch (std::exception e) {
        let a = parser->match(lexer, gap);
        match_memo[absIndex] = a;
        
        return a;
    }
    
}

auto TreeElement::parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const {
                   
    res.push_back(parser->parse(lexer));
}

auto TreeElement::rstride(Lexer& lexer, int gap) -> int const {
    let absIndex = lexer.absIndex(gap);
    try {
        return rstride_memo.at(absIndex);
    } catch (std::exception e) {
        let rs = parser->rstride(lexer, gap);
        rstride_memo[absIndex] = rs;
        
        return rs;
    }
}

auto TreeElement::description() -> std::string const{
    return "[Tree]";
}
