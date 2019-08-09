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
    std::string _message;
    
public:
    WorkFlowError(std::string __message):
    runtime_error("") , _message(__message){};
    
    var message() {
        return std::string("[WorkFlowError] ") + _message;
    }
    
};

}
#endif /* WorkFlowError_h */
