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
#include "WorkFlowError.hpp"

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

    wf::Parser expr = expr0.expression(primary, operators);
    
    wf::Parser statement0 = wf::rule();
    
    wf::Parser block = wf::rule<wf::ast::BlockStem>()
        .skip("{").optional(statement0)
        .optionalRepeat(wf::rule().skipEol().optional(statement0))
        .skip("}");
    
    wf::Parser statement = statement0.ors({
        wf::rule<wf::ast::IfStem>().skip("if").then(expr).then(block).optional(wf::rule().skip("else").then(block)),
        wf::rule<wf::ast::WhileStem>().skip("while").then(expr).then(block),
        wf::rule<wf::ast::VarStem>().skip("def").then(wf::Parser::name()).skip("=").then(expr),
        
        wf::rule<wf::ast::Assgin>().then(wf::Parser::name()).skip("=").then(expr),
        wf::rule<wf::ast::Calling>().then(wf::Parser::name()).skip("(").then(expr).skip(")"),
        expr,
    });
    
    wf::Parser program = wf::rule().ors({statement, wf::rule()}).skipEol();

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
        if (program.match(lexer)){
            return program.parse(lexer);
        }
        throw wf::WorkFlowError("Syntax Error at: " + lexer.description(0));
    }
};



#endif /* BasicParsers_h */
