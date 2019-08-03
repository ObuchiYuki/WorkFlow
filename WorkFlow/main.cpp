//
//  main.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/16.
//  Copyright © 2019 yuki. All rights reserved.
//


/**
 // TODO: - 各オブジェクトのネストを浅くする。
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Common.hpp"
#include "rmkit.h"

#include "Lexer/Lexer.hpp"
#include "ASTree.hpp"
#include "Runner.hpp"

using namespace wf;

int main() {

    let path = "/Users/yuki/Developer/Git/WorkFlow/main.wf";
    var ifs = std::ifstream(path);

    
    var lexer = wf::Lexer(&ifs);
    
    var env = wf::run::Environment();
    
    
    while (lexer.peek(0)->type != token::TokenType::ENDFILE) {
        let ps = BasicParsers().statement.parse(lexer);
        
        ps->eval(env);
    }
}