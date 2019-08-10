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
#include "WorkFlowError.hpp"

int main() {
    
    let path = "/Users/yuki/Developer/Git/WorkFlow/main.wf";
    var ifs = std::ifstream(path);
    
    var lexer = wf::Lexer(ifs);

    let f = BasicParser().argments.parse(lexer);
    
    print(f);
    
    return 0;
    var globalEnv = std::shared_ptr<wf::run::Environment>(new wf::run::Environment());
          

    // MARK: - Measure Start -
    rm::debug::startMeasure();

    try {
        while (!lexer.isEnd()) {
        
            var parser = FuncParser();
            let ps = FuncParser().parse(lexer);
            
            print(ps->description());
            
        }
    }catch(wf::WorkFlowError e) {
        rm::debug::out(e.message());
    }
    
    // MARK: - Measure End -
    rm::debug::endMeasure();
}
