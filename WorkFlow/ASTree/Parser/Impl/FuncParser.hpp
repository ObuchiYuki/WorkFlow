//
//  FuncParser.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/08.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef FuncParser_h
#define FuncParser_h

#include "BasicParser.hpp"
#include "Parser.hpp"
#include "AST.hpp"

class FuncParser: public BasicParser {
public:
    wf::Parser param = wf::Parser::name();
    
    wf::Parser params = wf::rule<wf::ast::ParameterList>()
                        .then(param).optionalRepeat(wf::rule().skip(",").then(param));
    
    wf::Parser paramList = wf::rule().skip("(").optional(params).skip(")");
    
    wf::Parser funcDef = wf::rule<wf::ast::FuncStem>()
                     .skip("def").then(wf::Parser::name()).then(paramList).then(block);

    FuncParser() {
        statement.insertChoise(funcDef);
    }
};



#endif /* FuncParser_h */
