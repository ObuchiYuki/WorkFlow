//
//  BasicParsers.h
//  WorkFlow
//
//  Created by yuki on 2019/08/02.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef BasicParsers_h
#define BasicParsers_h

#include "Lexer.hpp"
#include "Parser.hpp"

class BasicParser {
public:
    wf::Operators operators = wf::Operators();
    
    wf::Parser expr0 = wf::rule();
    
    wf::Parser primary = wf::rule().ors({
        wf::Parser::integer(),
        wf::Parser::name(),
        wf::Parser::string(),
        wf::rule<wf::ast::Expression>().skip("(").then(expr0).skip(")"),
    });
    
    wf::Parser calling0 = wf::rule();

    wf::Parser basicexpr = expr0.expression(primary, operators);
    
    wf::Parser expr = wf::rule<wf::ast::Expression>().ors({
        basicexpr,
        calling0,
    });
    
    wf::Parser calling = calling0.then(wf::rule<wf::ast::Calling>().then(wf::Parser::name()).skip("(").then(expr).skip(")"));
    
    wf::Parser statement0 = wf::rule();
    
    wf::Parser block = wf::rule<wf::ast::BlockStem>()
        .skip("{").optional(statement0)
        .repeat(wf::rule().skip("EOL").optional(statement0))
        .skip("}");
    
    wf::Parser statement = statement0.ors({
        wf::rule<wf::ast::IfStem>().skip("if").then(expr).then(block).optional(wf::rule().skip("else").then(block)),
        wf::rule<wf::ast::WhileStem>().skip("while").then(expr).then(block),
        wf::rule<wf::ast::VarStem>().skip("def").then(wf::Parser::name()).skip("=").then(expr),
        
        wf::rule<wf::ast::Assgin>().then(wf::Parser::name()).skip("=").then(expr),
        calling,
        expr,
    });
    
    wf::Parser program = wf::rule().ors({statement, wf::rule<wf::ast::NullStem>()}).skip("EOL");

    BasicParser() {
        operators.add("=", 1,   wf::Associative::RIGHT);
        operators.add("==", 2,  wf::Associative::LEFT);
        operators.add("+=", 2,  wf::Associative::LEFT);
        operators.add(">", 2,   wf::Associative::LEFT);
        operators.add("<", 2,   wf::Associative::LEFT);
        operators.add("+", 3,   wf::Associative::LEFT);
        operators.add("-", 3,   wf::Associative::LEFT);
        operators.add("*", 4,   wf::Associative::LEFT);
        operators.add("/", 4,   wf::Associative::LEFT);
        operators.add("%", 4,   wf::Associative::LEFT);
        
        wf::Parser::addReservedWord("if");
        wf::Parser::addReservedWord("while");
        wf::Parser::addReservedWord("def");
        wf::Parser::addReservedWord("else");
    }
    
    wf::ast::NodePtr parse(wf::Lexer& lexer) {
        return program.parse(lexer);
    }
};



#endif /* BasicParsers_h */