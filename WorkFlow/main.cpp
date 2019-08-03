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
#include "rmkit.h"

#include "Lexer/Lexer.hpp"
#include "ASTree.hpp"
#include "Runner.hpp"

using namespace wf;

int main() {
    

    let path = "/Users/yuki/Developer/C++/WorkFlow/main.wf";
    var ifs = std::ifstream(path);
    
    var lexer = wf::Lexer(&ifs);
    
    let ps = BasicParsers().statement.parse(lexer);
    
    
    var env = wf::run::Environment();
    ps->children[0]->eval(env);
    
}
