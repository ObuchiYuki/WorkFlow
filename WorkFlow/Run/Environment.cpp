//
//  Environment.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Environment.hpp"

#include <exception>
#include <string>
#include <vector>


using namespace wf::run;


auto Environment::get(std::string name) const -> Value {
    try {
        return variables.at(name);
    }catch(std::exception e) {
        for (auto &sub_env: sub_environments) {
            try {
                return sub_env->get(name);
            }catch(std::exception e) {}
        }
        throw wf::WorkFlowError("Cannot find Variable named " + name + ".");
    }
}

auto Environment::set(std::string name, Value token) -> void {
    variables[name] = token;
}


auto Environment::createSubEnv() -> EnvironmentPtr {
    auto sub = EnvironmentPtr(new Environment());
    EnvironmentPtr thisPtr = shared_from_this();
    sub->sub_environments.push_back(thisPtr);
    
    
    return sub;
}

