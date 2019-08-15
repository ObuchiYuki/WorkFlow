//
//  AssginStem.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef AssginStem_hpp
#define AssginStem_hpp

#include "Node.hpp"
#include "Leaf.hpp"


namespace wf {namespace ast {

    class AssginStem: public Node {
    public:
        
        // MARK: - Propertires -
        var target() const -> NodePtr;
        var value() const -> NodePtr;
        
        // MARK: - Constructor -
        AssginStem(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {}
        
        /// 今だけ
        auto eval(wf::run::EnvironmentPtr env) -> wf::run::Value override {
            let target_name = nodeAsLeaf(target())->token->value;
            let v_value = target()->eval(env);
            
            env->set(target_name, v_value);
            
            return wf::run::Value::voidValue();
        }
          
        
        // MARK: - Methods -
        auto description() const -> std::string override;
        
    };

}}


#endif /* AssginStem_hpp */
