//
//  BinaryOperation.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef BinaryOperation_hpp
#define BinaryOperation_hpp

#include "Node.hpp"
#include "Expression.hpp"
#include "Type.hpp"
#include "Leaf.hpp"

#include "WorkFlowError.hpp"

namespace wf { namespace ast {

class BinaryOperation: public Expression {
    
    type::FunctionTypePtr _checkedOp;
    
public:
    
    var left() const -> ExpressionPtr;
    var right() const -> ExpressionPtr;
    
    /// 今だけ
    var ops() const -> NodePtr {
        return children[1];
    }
    
    var op(wf::type::TypeEnvironment& env) -> type::FunctionTypePtr;
    
    var returnType(wf::type::TypeEnvironment& env) -> wf::type::TypePtr override {
        return op(env)->returnType;
    }
        
    /// 今だけ
    auto eval(wf::run::EnvironmentPtr env) -> wf::run::Value override {
        let op_s = wf::ast::nodeAsLeaf(ops())->token->value;
        let lsh = left()->eval(env);
        let rsh = right()->eval(env);
        
        if (op_s == "<") {
            return wf::run::Value(lsh.integer() < rsh.integer());
        }else if (op_s == ">") {
            return wf::run::Value(lsh.integer() > rsh.integer());
        }else if (op_s == "%") {
            return wf::run::Value(lsh.integer() % rsh.integer());
        }else if (op_s == "+") {
            return wf::run::Value(lsh.integer() + rsh.integer());
        }else if (op_s == "-") {
            return wf::run::Value(lsh.integer() - rsh.integer());
        }else if (op_s == "*") {
            return wf::run::Value(lsh.integer() * rsh.integer());
        }else if (op_s == "/") {
            return wf::run::Value(lsh.integer() / rsh.integer());
        }else if (op_s == "==") {
            return wf::run::Value(lsh.integer() == rsh.integer());
        }
        
        throw WorkFlowError("No matching operator");
    }
    
    BinaryOperation(std::vector<NodePtr> _children, Location _location) : Expression(_children, _location) {}
    
    var description() const -> std::string override;
};

}}

#endif /* BinaryOperation_hpp */
