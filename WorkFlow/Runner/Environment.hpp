//
//  Environment.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/01.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Environment_hpp
#define Environment_hpp

#include <vector>
#include <memory>
#include <unordered_map>

#include "../Lexer/Token.hpp"


namespace wf {namespace run{

typedef std::shared_ptr<wf::token::Token> TokenPtr;

class Environment {
private:
    std::unordered_map<std::string, TokenPtr> variables;

public:
    auto get(std::string name) -> TokenPtr {
        return variables[name];
    }
    auto set(std::string name, TokenPtr token) {
        variables[name] = token;
    }
};

}}

#endif /* Environment_hpp */
