//
//  BasicParsers.h
//  WorkFlow
//
//  Created by yuki on 2019/08/02.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef BasicParsers_h
#define BasicParsers_h

class BasicParsers {
public:
    wf::Operators ops = wf::Operators({
        wf::Operator("=", 1, wf::Associative::RIGHT),
        wf::Operator("==", 2, wf::Associative::LEFT),
        wf::Operator("+=", 2, wf::Associative::LEFT),
        wf::Operator(">", 2, wf::Associative::LEFT),
        wf::Operator("<", 2, wf::Associative::LEFT),
        wf::Operator("+", 3, wf::Associative::LEFT),
        wf::Operator("-", 3, wf::Associative::LEFT),
        wf::Operator("*", 4, wf::Associative::LEFT),
        wf::Operator("/", 4, wf::Associative::LEFT),
        wf::Operator("%", 4, wf::Associative::LEFT),
    });
    
    wf::Parser expr0 = wf::rule();
    
    wf::Parser primary = wf::rule().ors({
        wf::Parser::integer(),
        wf::Parser::name(),
        wf::Parser::string(),
        wf::rule<wf::ast::Expression>().skip("(").then(expr0).skip(")"),
    });
    
    wf::Parser expr = expr0.expression(primary, ops);
    
    wf::Parser statement0 = wf::rule();
    
    wf::Parser block = wf::rule<wf::ast::BlockStem>()
        .skip("{").optional(statement0)
        .repeat(wf::rule().skip("EOL").optional(statement0))
        .skip("}");
    
    wf::Parser statement = statement0.ors({
        wf::rule<wf::ast::IfStem>().skip("if").then(expr).then(block).optional(wf::rule().skip("else").then(block)),
        wf::rule<wf::ast::WhileStem>().skip("while").then(expr).then(block),
        wf::rule<wf::ast::VarStem>().skip("def").then(wf::Parser::name()).skip("=").then(expr),
        
        wf::rule<wf::ast::Calling>().then(wf::Parser::name()).skip("(").then(expr).skip(")"),
        wf::rule<wf::ast::Assgin>().then(wf::Parser::name()).skip("=").then(expr),
        expr,
    });
    
    wf::Parser program = wf::rule().ors({statement, wf::rule<wf::ast::NullStem>()}).skip("EOL");

};



#endif /* BasicParsers_h */
