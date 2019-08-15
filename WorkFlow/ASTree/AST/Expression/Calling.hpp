//
//  Calling.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/04.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Calling_h
#define Calling_h

#include "Expression.hpp"
#include "ArgumentList.hpp"
#include "PrimaryNode.hpp"

namespace wf {namespace ast{

class Calling: public Expression {
    type::TypePtr _checkedReturn;
public:
    // MARK: - Properties -
    
    var target() const -> std::string;
    var args() const -> std::shared_ptr<ArgumentList>;
    var returnType(wf::type::TypeEnvironment& env) -> type::TypePtr override;
    
    auto typeCheck(type::TypeEnvironment& env) -> void override {
        let func_s = env.getType(target());
        
        if (func_s != nullptr) {
            let func_type = std::dynamic_pointer_cast<type::FunctionType>(func_s);
            
            if (func_type->arguments == args()->argumentTypes(env)) {
                
                _checkedReturn = func_type->returnType;
                return;
            }
        }
        
        throw WorkFlowError("Function " + target() + " for this arg type is not defined.");
    }
    
    // MARK: - Constructor -
    Calling(std::vector<NodePtr> _children, Location _location);
    
    // MARK: - Methods -
    auto description() const -> std::string override;

};


}}
#endif /* Calling_h */
