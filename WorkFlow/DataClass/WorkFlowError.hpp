//
//  WorkFlowError.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef WorkFlowError_h
#define WorkFlowError_h

#include <string>
#include <exception>

#include "rmkit.h"

#include "Lexer.hpp"

namespace wf {


class WorkFlowError: public std::runtime_error {
    rm::optional<wf::Lexer> lexer;
    std::string _message;
    
public:
    WorkFlowError(std::string __message, wf::Lexer _lexer):
    runtime_error("") , lexer(_lexer), _message(__message){};
    
    WorkFlowError(std::string __message):
    runtime_error("") , lexer(nil), _message(__message){};
    
    var message() {
        if (lexer){
            return std::string("[WorkFlowError] ") + _message + " around " + lexer->peek(0)->location.description();
        }else{
            return std::string("[WorkFlowError] ") + _message;
        }
    }
    
};

}
#endif /* WorkFlowError_h */
