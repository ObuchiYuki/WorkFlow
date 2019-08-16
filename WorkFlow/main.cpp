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
#include "LLVM.h"

int main() {
    var context = wf::llvm::Context("@main", "i32");
    
    context.assign("%a", "i32", "10");
    context.blank();
    context.assign("%b", "i32", "5");
    context.blank();
    context.add("%r", "i32", "%a", "%b");
    
    print(context.llvmstring());
    
    return 0;
    let path = "/Users/yuki/Developer/Git/WorkFlow/main.wf";
    var ifs = std::ifstream(path);
    
    var lexer = wf::Lexer(ifs);
        
    wf::type::PrimitiveType::registerAll();
    
    auto globalEnv = wf::type::TypeEnvironment("__global", wf::type::Type::global);
    
    // MARK: - Measure Start -
    rm::debug::startMeasure();
    
    try{
        var parser = ClassParser();
        let ps = parser.parse(lexer);
            
        ps->typeCheck(globalEnv);
        
        print(ps->description());
        
    }catch(wf::WorkFlowError e){
        
        print(e.message());
    }
    
    // MARK: - Measure End -
    rm::debug::endMeasure();
}
