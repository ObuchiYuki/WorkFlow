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
    auto t1 = std::chrono::high_resolution_clock::now();

    let path = "/Users/yuki/Developer/Git/WorkFlow/main.wf";
    var ifs = std::ifstream(path);

    
    var lexer = wf::Lexer(&ifs);
    
    var env = wf::run::Environment();
        
    while (lexer.peek(0)->type != token::TokenType::ENDFILE) {
        
        let ps = BasicParsers().program.parse(lexer);        
        
        ps->eval(env);
    }
    

    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    print("⏰", duration / double(1000 * 1000), "s");
    
    // take almost 1 sec....
    
    return 0;
    
}
