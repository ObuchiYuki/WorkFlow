//
//  Function.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Function.hpp"

#include <string>
#include "Argument.hpp"
#include "ArgumentList.hpp"
#include "ParameterList.hpp"

using namespace wf::run;


auto Function::createIdentifier(std::string name, wf::ast::ArgumentList arguments) -> std::string {
    if (arguments.numArgument() == 0){return name + "()";}
    std::string idName = name + std::string("(");
    
    let allarguments = arguments.arguments();
    
    
    idName += allarguments[0]->label();
    for (int i = 1, c = arguments.numArgument(); i < c; ++i) {
        idName += std::string(",") + allarguments[i]->label();
    }
    
    idName += ")";
    
    return idName;
}
auto Function::createIdentifier(std::string name, ast::ParameterList paramators) -> std::string {
    if (paramators.numParamaters() == 0){return name + "()";}
    var idName = name + "(";
    
    
    idName += paramators.label(0);
    for (int i = 1, c = paramators.numParamaters(); i < c; ++i) {
        idName += ", " + paramators.label(i);
    }
    
    idName += ")";
    
    return idName;
}

auto Function::call(std::shared_ptr<wf::ast::ArgumentList> arguments, wf::run::EnvironmentPtr env) const -> Value{
    if (arguments->numArgument() != numParamators()) {
        throw wf::WorkFlowError(_createArgNumErrorMessage(arguments->numArgument()));
    }
    
    var subEnv = env->createSubEnv();
    for (int i=0; i<arguments->numArgument();i++) {
        subEnv->set(paramators->name(i), arguments->arg(i)->eval(env));
    }

    return block->eval(subEnv);
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


