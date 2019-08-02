//
//  main.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/16.
//  Copyright © 2019 yuki. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "rmkit.h"

#include "Common.hpp"

#include "Lexer/Lexer.hpp"
#include "ASTree.hpp"
#include "Runner.hpp"

using namespace wf;

int main() {
    rm::optional<int> value = 2;
    
    return 0;
    var ops = Operators();
    
    ops.add("=", 1, Associative::RIGHT);
    ops.add("==", 2, Associative::LEFT);
    ops.add(">", 2, Associative::LEFT);
    ops.add("<", 2, Associative::LEFT);
    ops.add("+", 3, Associative::LEFT);
    ops.add("-", 3, Associative::LEFT);
    ops.add("*", 4, Associative::LEFT);
    ops.add("/", 4, Associative::LEFT);
    ops.add("%", 4, Associative::LEFT);
    
    var expr0 = rule<ast::Expression>();
    
    var primary = rule<ast::PrimaryNode>().ors({
        rule<ast::Expression>().skip("(").then(expr0).skip(")"),
        p_integer,
        p_identifier,
        p_string
    });
    
    var expr = expr0.expression(primary, ops);

    var statement0 = rule();
    var block = rule<ast::BlockStem>()
        .skip("{").optional(statement0)
        .repeat(
            rule()
                .skip(std::vector<std::string>({";", "EOL"}))
                .optional(statement0)
            )
        .skip("}");
    
    
    var simple = rule().then(expr);
    
    var statement = statement0.ors({
        rule<ast::IfStem>().skip("if").then(expr).then(block).optional(rule().skip("else").then(block)),
        rule<ast::WhileStem>().skip("while").then(expr).then(block),
        rule<ast::VarStem>().skip("def").then(p_identifier).skip("=").then(expr),
        rule<ast::Calling>().then(p_identifier).skip("(").then(expr).skip(")"),
        simple,
    });
    
    var program = rule().optional(statement).skip(std::vector<std::string>({";", "EOL"}));


    let path = "/Users/yuki/Developer/C++/WorkFlow/main.wf";
    var ifs = std::ifstream(path);
    
    var lexer = wf::Lexer(&ifs);
    
    let ps = statement.parse(lexer);
    
    print(ps->children[0]->description());
}
