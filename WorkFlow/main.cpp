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
#include "TypeUmbrella.hpp"
#include "WorkFlowError.hpp"

int main() {

    let path = "/Users/yuki/Developer/Git/WorkFlow/main.wf";
    var ifs = std::ifstream(path);
    
    var lexer = wf::Lexer(ifs);
        
    wf::type::PrimitiveType::registerAll();
    
    wf::type::TypeEnvironment globalEnv;
    
    // MARK: - Measure Start -
    rm::debug::startMeasure();
    
    while (!lexer.isEnd()) {
            
        var parser = ClassParser();
        let ps = parser.parse(lexer);
            
        print(ps->description());
    }
    
    // MARK: - Measure End -
    rm::debug::endMeasure();
}
