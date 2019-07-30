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

#include "Common.hpp"

#include "Lexer/Lexer.hpp"
#include "Parser.hpp"

using namespace wf;

int main() {
    var expr0 = rule<ast::Expression>();
    
    var primary = rule<ast::PrimaryNode>().ors({
        rule().skip("(").then(expr0).skip(")"),
        p_integer,
        p_identifier,
        p_string
    });
                
    var factor = rule().ors({
        rule<ast::NegativeExpr>().skip("-").then(primary),
        primary
    });
    
    var expr = expr0.injected(
        rule().then(factor).repeat(
            rule().then(p_operator).then(factor)
        )
    );

    var varStem = rule<ast::VarStem>()
        .skip("def")
        .then(p_identifier)
        .skip("=")
        .then(expr);

    let path = "/Users/yuki/Developer/C++/WorkFlow/main.wf";
    var ifs = std::ifstream(path);
    
    var lexer = wf::Lexer(&ifs);
    
    std::cout << varStem.match(lexer) << std::endl;
    
    let ps = varStem.parse(lexer);
    
    std::cout << ps->description() << std::endl;
}
