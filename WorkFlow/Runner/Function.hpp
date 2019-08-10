//
//  Function.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Function_hpp
#define Function_hpp

#include <string>
#include <vector>
#include <memory>

#include "Node.hpp"

#include "WorkFlowError.hpp"
#include "ParameterList.hpp"
#include "BlockStem.hpp"
#include "Argument.hpp"
#include "ArgumentList.hpp"
#include "PrimaryNode.hpp"


namespace wf {namespace run{

class Function {
public:
    
    ///def hello(to world, with him) -> hello(to, with)
    std::string identifier;
private:
    
    std::shared_ptr<wf::ast::ParameterList> paramators;
    std::shared_ptr<wf::ast::BlockStem> block;
    
    
public:
    auto createIdentifier(std::string name, ast::ParameterList paramators) -> std::string {
        var idName = name + "(";
        
        idName += paramators.label(0);
        for (int i = 1, c = paramators.numParamaters(); i < c; ++i) {
            idName += ", " + paramators.label(i);
        }
        
        idName += ")";
        
        return idName;
    }
    
    Function(std::shared_ptr<ast::Name> name, std::shared_ptr<ast::ParameterList> _paramators, std::shared_ptr<ast::BlockStem> _block) :
    paramators(_paramators), block(_block)
    {
        var id = name->token->value + "(";
        
    }
    
    auto call(std::shared_ptr<wf::ast::ArgumentList> arguments, wf::run::EnvironmentPtr env) {
        if (arguments->numArgument() != numParamators()) {
            throw wf::WorkFlowError(_createArgNumErrorMessage(arguments->numArgument()));
        }
        
        var subEnv = env->createSubEnv();
        for (int i=0; i<arguments->numArgument();i++) {
            subEnv->set(paramators->name(i), arguments->arg(i)->eval(env));
        }
        
        block->eval(subEnv);

    }
    auto numParamators() const -> int {
        return paramators->numChildren();
    }
    
    auto description() -> std::string {
        return "[Function] " + identifier;
    }
    
private:
    auto _createArgNumErrorMessage(int givenArgnum) const -> std::string {
        return "[Function::call] This function " + identifier + " requires "
        + std::to_string(numParamators()) + "arguments" + ", but " + std::to_string(givenArgnum) + "were given.";
    }
};

}}

#endif /* Function_hpp */
