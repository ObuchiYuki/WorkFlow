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
#include "WorkFlowError.hpp"
#include "Value.hpp"


namespace wf {namespace run{

class Environment;
typedef std::shared_ptr<Environment> EnvironmentPtr;

class Environment: public std::enable_shared_from_this<Environment> {
public:
    std::unordered_map<std::string, Value> variables = {};
    std::vector<EnvironmentPtr> sub_environments = {};
    

    auto get(std::string name) const -> Value;
    auto set(std::string name, Value token) -> void;
    auto createSubEnv() -> EnvironmentPtr;
    
    friend std::ostream& operator << (std::ostream &os, const Environment self) {
        for (let &item: self.variables){ os << item.first << " => " << item.second << std::endl; }
        
        return os;
    }
};



}}

#endif /* Environment_hpp */
