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

#include "Token.hpp"
#include "Value.hpp"


namespace wf {namespace run{

class Environment {
private:
    std::unordered_map<std::string, Value> variables = {};

public:
    auto get(std::string name) -> Value {
        return variables[name];
    }
    auto set(std::string name, Value token) {
        variables[name] = token;
    }
};

}}

#endif /* Environment_hpp */
