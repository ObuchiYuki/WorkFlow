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


namespace wf {namespace ast {

    class AssginStem: public Node {
    public:
        auto target() -> NodePtr {
            return children[0];
        }
        auto value() -> NodePtr{
            return children[2];
        }
            
        AssginStem(std::vector<NodePtr> _children, Location _location) :
            Node(_children, _location) {}
            
        auto description() -> std::string const override {
            return "(" + target()->description() + " = " + value()->description() + ")";
        }

        wf::run::Value eval(wf::run::Environment& env) override {
            let s_target = nodeAsLeaf(target())->token->value;
            var r_value = value()->eval(env);

            env.set(s_target, r_value);
            
            return wf::run::Value::voidValue();
        }
    };

}}


#endif /* AssginStem_hpp */
