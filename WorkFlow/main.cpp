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
#include <chrono>

#include "Common.hpp"
#include "rmkit.h"

#include "Lexer/Lexer.hpp"
#include "ASTree.hpp"
#include "Runner.hpp"



using namespace wf;

int main() {
    rm::debug::startMeasure();
    let path = "/Users/yuki/Developer/Git/WorkFlow/main.wf";
    var ifs = std::ifstream(path);
    
    var lexer = wf::Lexer(&ifs);
    
    var env = wf::run::Environment();
             
    while (lexer.peek(0)->type != token::TokenType::ENDFILE) {
        
        let ps = FuncParser().program.parse(lexer);
        
        ps->eval(env);

    }
    
    rm::debug::endMeasure();
    
    return 0;
    
}
