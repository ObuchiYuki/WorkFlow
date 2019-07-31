//
//  Parser.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Parser.hpp"

using namespace wf;

// MARK: - Constructor -

Parser::Parser(_ParserPtr _parser) : parser(_parser) {};

// MARK: - Methods -
 
auto Parser::parse(Lexer& lexer) -> NodePtr {
    
    return parser->parse(lexer);
}
        
 
auto Parser::match(Lexer& lexer) -> bool{
    return parser->match(lexer);
}


auto Parser::ors(std::vector<Parser> parserws) -> Parser{
    std::vector<_ParserPtr> parsers;
            
    for (let &pw:parserws){
        parsers.push_back(pw.parser);
    }
            
    let e_or = ElementPtr(new OrElement(parsers));
            
    parser->addElement(e_or);
        
    return *this;
}
        
 
auto Parser::repeat(Parser parserw) -> Parser{
    let e_repeat = ElementPtr(new RepeatElement(parserw.parser, false));
            
    parser->addElement(e_repeat);
            
    return *this;
}

 
auto Parser::skip(std::string token) -> Parser{
    let e_skip =  ElementPtr(new SkipElement(token));
            
    parser->addElement(e_skip);
        
    return *this;
}

 
auto Parser::then(Parser parserw) -> Parser{
    let e_tree = ElementPtr(new TreeElement(parserw.parser));
            
    parser->addElement(e_tree);
                        
    return *this;
}
     
 
auto Parser::expression(Parser subParserw, Operators ops) -> Parser{
    let e_expr = ElementPtr(new ExprElement(subParserw.parser, ops));
            
    parser->addElement(e_expr);
            
    return *this;
}

auto Parser::optional(Parser parserw) -> Parser{
    let e_repeat = ElementPtr(new RepeatElement(parserw.parser, true));
                
    parser->addElement(e_repeat);
                
    return *this;
}
