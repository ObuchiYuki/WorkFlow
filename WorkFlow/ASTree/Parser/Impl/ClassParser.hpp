//
//  ClassParser.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/14.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef ClassParser_h
#define ClassParser_h

#include "FuncParser.hpp"
#include "ClassStem.hpp"

class ClassParser: public FuncParser {
public:
    wf::Parser classBody0 = wf::rule<wf::ast::BlockStem>();
    
    wf::Parser classDef = wf::rule<wf::ast::ClassStem>()
    .skip("class").then(wf::Parser::name()).then(classBody0);
     
    wf::Parser inclassStem = wf::rule().ors({
        varStem,
        funcDef,
        classDef,
        wf::rule().skipEol(),
    });
    
    wf::Parser classBody = classBody0
        .skip("{").optional(inclassStem)
            .optionalRepeat(wf::rule().skipEol().optional(inclassStem))
        .skip("}");
        
    
    ClassParser() {
        wf::Parser::addReservedWord("class");
        
        program.insertChoise(classDef);
    }
};


#endif /* ClassParser_h */
