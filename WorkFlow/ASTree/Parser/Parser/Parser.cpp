//
//  Parser.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Parser.hpp"

#include <vector>
#include <string>

#include "rmkit.h"

using namespace wf;

// MARK: - Constructor -

Parser::Parser(_ParserPtr _parser) : parser(_parser) {};

// MARK: - Methods -
 
auto Parser::parse(Lexer& lexer) -> ast::NodePtr {
    
    return parser->parse(lexer);
}
        
 
auto Parser::match(Lexer& lexer) -> bool {
    return parser->match(lexer, 0);
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
auto Parser::optional(Parser parserw) -> Parser{
    let e_repeat = ElementPtr(new RepeatElement(parserw.parser, true));
                
    parser->addElement(e_repeat);
                
    return *this;
}
 
auto Parser::skip(std::string token) -> Parser{
    let e_skip = ElementPtr(new SkipElement(token));
            
    parser->addElement(e_skip);
        
    return *this;
}

auto Parser::skip(std::vector<std::string> tokens) -> Parser {
    let e_skip =  ElementPtr(new SkipElement(tokens));
    
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

auto Parser::insertChoise(Parser parserw) -> Parser {
    auto& elm0 = parser->getElements()[0];
    auto orElm = std::dynamic_pointer_cast<OrElement>(elm0);
    
    if (orElm) {
        orElm->insertChoise(parserw.parser);
        
        return *this;
    }
    throw std::runtime_error("[Parser::insertChoise] Parser.elements[0] is not OrElement. Check if elements[0] is OrElement.");
}

auto Parser::_integer() -> Parser {
    let e_int = ElementPtr(new IntegerElement());
    
    parser->addElement(e_int);
    
    return *this;
}
auto Parser::_string() -> Parser {
    let e_str = ElementPtr(new StringElement());
    
    parser->addElement(e_str);
    
    return *this;
}
auto Parser::_name() -> Parser {
    let e_id = ElementPtr(new IDElement());
    
    parser->addElement(e_id);
    
    return *this;
}
auto Parser::_op() -> Parser {
    let e_ops = ElementPtr(new OperatorElement());
    
    parser->addElement(e_ops);
    
    return *this;
}


auto Parser::integer() -> Parser {
    return rule()._integer();
}
auto Parser::string() -> Parser {
    return rule()._string();
}
auto Parser::name() -> Parser {
    return rule()._name();
}
auto Parser::op() -> Parser {
    return rule()._op();
}
