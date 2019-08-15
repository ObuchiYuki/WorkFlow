//
//  VarStem.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef VarStem_h
#define VarStem_h

#include <string>

#include "Location.hpp"
#include "Node.hpp"
#include "TypeSpecifier.hpp"
#include "Type.hpp"
#include "Expression.hpp"

namespace wf {namespace ast{

/**
 def i = 1
 iの方は常に自動で予測する
 */
class VarStem: public Node {
public:
    var valueType(wf::type::TypeEnvironment& env) const -> type::TypePtr;
    
    var target() const -> std::string;
    var init() const -> ExpressionPtr;
            
    VarStem(std::vector<NodePtr> _children, Location _location);
    
    auto typeCheck(type::TypeEnvironment& env) -> void {
        env.registerProperty(type::PropertyPtr(new type::Property(target(), valueType(env))));
        
    }
    
    var description() const -> std::string override;
        
};

}}


#endif /* VarStem_h */
