
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
RepeatElement::RepeatElement(_ParserPtr _parser, bool _once) : parser(_parser), once(_once) {
    
}

// MARK: - Methods -
auto RepeatElement::match(Lexer& lexer) -> bool const {
    return parser->match(lexer);
}

auto RepeatElement::parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const {
                   
    while (parser->match(lexer)) {
        let node = parser->parse(lexer);
        
        if (node->numChildren() > 0) res.push_back(node);
        if (once) break;
    }
}
