//
//  ExAssign.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef ExAssign_hpp
#define ExAssign_hpp

#include "Node.hpp"

namespace wf {namespace ast {

class AddAssignStem: public Node {
public:
    // MARK: - Properties -
    
    var target() const -> NodePtr;
    var value() const -> NodePtr;
    
    var description() const -> std::string override;
    
    /// 今だけ
    auto eval(wf::run::EnvironmentPtr env) -> wf::run::Value override {
        let target_name = nodeAsLeaf(target())->token->value;
        let v_target = target()->eval(env).integer();
        let v_value = target()->eval(env).integer();
        
        env->set(target_name, wf::run::Value(v_target + v_value));
        
        return wf::run::Value::voidValue();
    }
    
    // MARK: - Constructor -
    AddAssignStem(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {};

};


class DecAssignStem: public Node {
public:
    // MARK: - Properties -
    
    var target() const -> NodePtr;
    var value() const -> NodePtr;
    
    var description() const -> std::string override;
    
    /// 今だけ
    auto eval(wf::run::EnvironmentPtr env) -> wf::run::Value override {
        let target_name = nodeAsLeaf(target())->token->value;
        let v_target = target()->eval(env).integer();
        let v_value = target()->eval(env).integer();
        
        env->set(target_name, wf::run::Value(v_target - v_value));
        
        return wf::run::Value::voidValue();
    }
    
    // MARK: - Constructor -
    DecAssignStem(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {};

};

}}

#endif /* ExAssign_hpp */
