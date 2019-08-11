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
    static auto createIdentifier(std::string name, ast::ParameterList paramators) -> std::string;
    static auto createIdentifier(std::string name, ast::ArgumentList arguments) -> std::string;
    
    Function(std::shared_ptr<ast::Name> name, std::shared_ptr<ast::ParameterList> _paramators, std::shared_ptr<ast::BlockStem> _block) :
    paramators(_paramators), block(_block)
    {
        identifier = Function::createIdentifier(name->token->value, *_paramators);
        
    }
    
    auto call(std::shared_ptr<wf::ast::ArgumentList> arguments, wf::run::EnvironmentPtr env) const -> wf::run::Value;
    
    auto numParamators() const -> int;
    
    auto description() -> std::string;
    
private:
    auto _createArgNumErrorMessage(int givenArgnum) const -> std::string;
};

}}

#endif /* Function_hpp */
