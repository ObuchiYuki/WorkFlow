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

#include "location.hpp"
#include "Environment.hpp"
#include "Node.hpp"
#include "TypeSpecifier.hpp"
#include "Type.hpp"

namespace wf {namespace ast{

/**
 def i = 1
 */
class VarStem: public Node {
public:
    type::TypePtr valueType; // == init() return type
    
    
    var target() const -> std::string; // nonnull
    var init() const -> NodePtr; // nullable
            
    VarStem(std::vector<NodePtr> _children, Location _location);
    
    var description() const -> std::string override;
        
    auto eval(wf::run::EnvironmentPtr env) const -> wf::run::Value override;
};

}}


#endif /* VarStem_h */
