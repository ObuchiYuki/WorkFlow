//
//  main.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/16.
//  Copyright © 2019 yuki. All rights reserved.
//

#include <fstream>

#include "Common.hpp"
#include "rmkit.h"

#include "Lexer/Lexer.hpp"
#include "ASTree.hpp"
#include "Runner.hpp"


int main() {
    
    let path = "/Users/yuki/Developer/Git/WorkFlow/main.wf";
    var ifs = std::ifstream(path);
    
    var lexer = wf::Lexer(ifs);
    
    var env = wf::run::Environment();
          
    
    // MARK: - Measure Start -
    rm::debug::startMeasure();

    while (!lexer.isEnd()) {
        
        let ps = FuncParser().program.parse(lexer);
        
        ps->eval(env);

    }
    
    // MARK: - Measure End -
    rm::debug::endMeasure();
}
