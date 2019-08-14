//
//  main.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/16.
//  Copyright © 2019 yuki. All rights reserved.
//

#include <fstream>
#include <sstream>

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
        
    var llvm = std::stringstream();
    
    var globalEnv = std::shared_ptr<wf::run::Environment>(new wf::run::Environment());

    // MARK: - Measure Start -
    rm::debug::startMeasure();
    
    llvm << "define i64 @main() {\n";

    try {
        while (!lexer.isEnd()) {
            
            var parser = ClassParser();
            let ps = parser.parse(lexer);
              
            llvm->eval(globalEnv);
            //llvm << ps->llvm();
        }
    }catch(wf::WorkFlowError e) {
        rm::debug::out(e.message());
    }
    
    llvm << "ret i64 1\n";
    llvm << "}";
    
    print(llvm.str());
    
    // MARK: - Measure End -
    rm::debug::endMeasure();
}
