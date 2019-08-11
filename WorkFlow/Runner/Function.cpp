//
//  Function.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Function.hpp"

#include <string>

using namespace wf::run;


auto Function::createIdentifier(std::string name, ast::ParameterList paramators) -> std::string {
    var idName = name + "(";
    
    idName += paramators.label(0);
    for (int i = 1, c = paramators.numParamaters(); i < c; ++i) {
        idName += ", " + paramators.label(i);
    }
    
    idName += ")";
    
    return idName;
}

auto Function::call(std::shared_ptr<wf::ast::ArgumentList> arguments, wf::run::EnvironmentPtr env) {
    if (arguments->numArgument() != numParamators()) {
        throw wf::WorkFlowError(_createArgNumErrorMessage(arguments->numArgument()));
    }
    
    var subEnv = env->createSubEnv();
    for (int i=0; i<arguments->numArgument();i++) {
        subEnv->set(paramators->name(i), arguments->arg(i)->eval(env));
    }
    
    block->eval(subEnv);

}

auto Function::numParamators() const -> int {
    return paramators->numChildren();
}

auto Function::description() -> std::string {
    return "[Function] " + identifier;
}
    
auto Function::_createArgNumErrorMessage(int givenArgnum) const -> std::string {
    return "[Function::call] This function " + identifier + " requires "
    + std::to_string(numParamators()) + "arguments" + ", but " + std::to_string(givenArgnum) + "were given.";
}


