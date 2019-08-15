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
#include "ParserDebuger.hpp"

class BasicParser {
public:
    /// 演算子を格納します。
    wf::Operators operators = wf::Operators();
    
    /// タイプ指定子
    wf::Parser typespecifier = wf::rule<wf::ast::TypeSpecifier>()
        .skip(":").then(wf::rule().ors({
            wf::Parser::name(),
            wf::Parser::directive(),
        }));
    
    /// 式を表します。(1 + 3 * 3)...、実態はbasicExprにあります。
    wf::Parser basicExpr0 = wf::rule();
    
    /// 基本のノードを表します。
    /// Int、String、Name、式など
    wf::Parser primary = wf::rule().ors({
        wf::Parser::integer(),
        wf::Parser::name(),
        wf::Parser::string(),
        wf::rule().skip("(").then(basicExpr0).skip(")"),
    });

    /// 式を表します。(1 + 3 * 3)...
    wf::Parser basicExpr = basicExpr0.expression(primary, operators);
    
    /// 関数呼び出しです。実態はcallingにあります。
    wf::Parser calling0 = wf::rule<wf::ast::Calling>();
    
    /// 式を表します。
    wf::Parser expr = wf::rule().ors({
        calling0,
        basicExpr,
    });
    
    wf::Parser argment = wf::rule<wf::ast::Argument>()
        .optional(wf::rule().then(wf::Parser::name()).skip(":"))
        .then(expr);
    
    wf::Parser argments = wf::rule<wf::ast::ArgumentList>().then(argment).optionalRepeat(wf::rule().skip(",").then(argment));
    
    /// 関数呼び出しです。
    wf::Parser calling = calling0.then(wf::Parser::name()).skip("(").optional(argments).skip(")");
    
    /// 文を表します。実態はstatementにあります。
    wf::Parser statement0 = wf::rule();
    
    /// ブロックを表します。
    wf::Parser block = wf::rule<wf::ast::BlockStem>()
        .skip("{").optional(statement0)
        .optionalRepeat(wf::rule().skipEol().optional(statement0))
        .skip("}");
    
    wf::Parser assign = wf::rule().ors({
        wf::rule<wf::ast::AssginStem>().then(wf::Parser::name()).skip("=").then(expr),
        wf::rule<wf::ast::AddAssignStem>().then(wf::Parser::name()).skip("+=").then(expr),
        wf::rule<wf::ast::DecAssignStem>().then(wf::Parser::name()).skip("-=").then(expr),
    });
    
    wf::Parser VarStem = wf::rule<wf::ast::VarStem>().skip("def").then(wf::Parser::name()).skip("=").then(expr);
    
    /// 文を表します。(if while def...)
    wf::Parser statement = statement0.ors({
        wf::rule<wf::ast::IfStem>().skip("if").then(expr).then(block).optional(wf::rule().skip("else").then(block)),
        wf::rule<wf::ast::WhileStem>().skip("while").then(expr).then(block),
        
        VarStem,
        assign,
        expr,
        
    });
    
    wf::Parser programLine = wf::rule().ors({statement, wf::rule<wf::ast::NullStem>()}).skipEol();
    
    wf::Parser program = wf::rule<wf::ast::BlockStem>().optionalRepeat(programLine);

    BasicParser() {
        // MARK: - Add Operators -
        operators.add("=", 1,   wf::Associative::RIGHT);
        operators.add("==", 2,  wf::Associative::LEFT);
        operators.add(">", 2,   wf::Associative::LEFT);
        operators.add("<", 2,   wf::Associative::LEFT);
        operators.add("+", 3,   wf::Associative::LEFT);
        operators.add("-", 3,   wf::Associative::LEFT);
        operators.add("*", 4,   wf::Associative::LEFT);
        operators.add("/", 4,   wf::Associative::LEFT);
        operators.add("%", 4,   wf::Associative::LEFT);
        
        wf::Parser::addReservedWord("if");
        wf::Parser::addReservedWord("while");
        wf::Parser::addReservedWord("mut");
        wf::Parser::addReservedWord("def");
        wf::Parser::addReservedWord("else");
    }
    
    auto parse(wf::Lexer& lexer) -> wf::ast::NodePtr{
        if (program.match(lexer)){
            return program.parse(lexer);
        }

        throw wf::WorkFlowError("Syntax Error around: " + lexer.description(wf::ParserDebuger::getMaxMatch()));
    }
};



#endif /* BasicParsers_h */
