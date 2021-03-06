//
//  Arguments.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Arguments_hpp
#define Arguments_hpp

#include "Node.hpp"
#include "TypeUmbrella.hpp"
#include "Expression.hpp"
#include "rmkit.h"

namespace wf {namespace ast {

class Argument: public Node {
public:
    var label() const -> std::string;
    var value() const -> ExpressionPtr;
    
    auto returnType(type::TypeEnvironment &env) -> type::TypePtr {
        return value()->returnType(env);
    }
    
    Argument(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {}
        
    var description() const -> std::string override {
        if (numChildren() == 2) {
            return label() + " " + value()->description();
        }else{
            return value()->description();
        }
    }
};


}}

#endif /* Arguments_hpp */
