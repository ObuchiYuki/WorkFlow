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


namespace wf {namespace run{

class Function {
private:
    std::string identifier;
    std::shared_ptr<wf::ast::BlockStem> block;
    std::shared_ptr<wf::ast::ParameterList> paramators;
    
    
public:
    
    auto call(std::shared_ptr<wf::ast::ArgumentList> arguments, wf::run::Environment& env) {
        if (arguments->numArgument() != numParamators()) {
            throw wf::WorkFlowError(_createArgNumErrorMessage(arguments->numArgument()));
        }
        
        var subEnv = env.createSubEnv();
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
        "[Function::call] This function " + identifier + " requires "
        + std::to_string(numParamators()) + "arguments" + ", but " + std::to_string(givenArgnum) + "were given."
    }
}

}}

#endif /* Function_hpp */
