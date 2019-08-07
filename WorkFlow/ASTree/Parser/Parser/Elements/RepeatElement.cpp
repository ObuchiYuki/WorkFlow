
//
//  RepeatElement.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "RepeatElement.hpp"

#include <vector>

#include "Parser.hpp"
#include "Lexer.hpp"


using namespace wf;

// MARK: - Constructor -
RepeatElement::RepeatElement(_ParserPtr _parser, bool _once) : parser(_parser), isOptional(_once) {
    
}

// MARK: - Methods -
auto RepeatElement::rstride(Lexer& lexer, int gap) const -> int const {
    var rgap = gap;
    var rstride = 0;
    
    while(parser->match(lexer, rgap)) {
        let a = parser->rstride(lexer, rgap);
        rstride += a;
        rgap += a;
        
        if (isOptional) break;
    }

    return rstride;
}

auto RepeatElement::match(Lexer& lexer, int gap) const -> const bool {
    if (isOptional) return true;
    
    return parser->match(lexer, gap);
}

auto RepeatElement::parse(Lexer& lexer, std::vector<NodePtr> &res) const -> void {
    
    while (parser->match(lexer, 0)) {
        let node = parser->parse(lexer);
        
        if (node->numChildren() > 0) res.push_back(node);
        if (isOptional) break;
    }
}


auto RepeatElement::description() const -> const std::string {
    return "[Repeat " + parser->description() + "]";
}














