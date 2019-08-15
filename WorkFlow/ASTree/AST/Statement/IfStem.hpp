//
//  IfStem.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef IfStem_h
#define IfStem_h

#include <string>

#include "Location.hpp"
#include "Node.hpp"
#include "Expression.hpp"
#include "BlockStem.hpp"

namespace wf {namespace ast{


class IfStem:public Node {
public:
    auto condition() const -> std::shared_ptr<Expression>;
    auto block() const -> std::shared_ptr<BlockStem>;
        
    auto elseBlock()  const -> NodePtr;
        
    auto description() const -> std::string override;
    
    /// 今だけ
    auto eval(wf::run::EnvironmentPtr env) -> wf::run::Value override {
        if (condition()->eval(env).boolean()){
            block()->eval(env);
        }else{
            if (elseBlock()){
                elseBlock()->eval(env);
            }
        }
        
        return wf::run::Value::voidValue();
    }
    
    void typeCheck(type::TypeEnvironment &env) override {
        if (condition()->returnType(env) != type::PrimitiveType::Bool) {
            throw WorkFlowError("IfStem::typeCheck: condition expression dosen't return Bool.");
        }
        
        block()->typeCheck(env);
        if (elseBlock()) elseBlock()->typeCheck(env);
    }
        
    IfStem(std::vector<NodePtr> _children, Location _location);
        
};

}}


#endif /* IfStem_h */
