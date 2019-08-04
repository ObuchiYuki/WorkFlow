//
//  BasicParsers.h
//  WorkFlow
//
//  Created by yuki on 2019/08/02.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef BasicParsers_h
#define BasicParsers_h

// TODO: - 消す - 
using namespace wf;

class BasicParsers {
public:
    Operators ops = Operators({
        Operator("=", 1, Associative::RIGHT),
        Operator("==", 2, Associative::LEFT),
        Operator(">", 2, Associative::LEFT),
        Operator("<", 2, Associative::LEFT),
        Operator("+", 3, Associative::LEFT),
        Operator("-", 3, Associative::LEFT),
        Operator("*", 4, Associative::LEFT),
        Operator("/", 4, Associative::LEFT),
        Operator("%", 4, Associative::LEFT),
    });
    
    Parser expr0 = rule();
    
    Parser primary = rule().ors({
        rule<ast::Expression>().skip("(").then(expr0).skip(")"),
        Parser::integer(),
        Parser::name(),
        Parser::string(),
    });
    
    Parser expr = expr0.expression(primary, ops);
    
    Parser statement0 = rule();
    
    Parser block = rule<ast::BlockStem>()
    .skip("{").optional(statement0)
    .repeat(
            rule()
            .skip(std::vector<std::string>({";", "EOL"}))
            .optional(statement0)
            )
    .skip("}");
    
    
    Parser simple = rule().then(expr);
    
    Parser statement = statement0.ors({
        rule<ast::IfStem>().skip("if").then(expr).then(block).optional(rule().skip("else").then(block)),
        rule<ast::WhileStem>().skip("while").then(expr).then(block),
        rule<ast::VarStem>().skip("def").then(Parser::name()).skip("=").then(expr),
        rule<ast::Calling>().then(Parser::name()).skip("(").then(expr).skip(")"),
        simple,
    });
    
    Parser program = rule().then(statement).skip(std::vector<std::string>({";", "EOL"}));

};

    
    
    



#endif /* BasicParsers_h */
