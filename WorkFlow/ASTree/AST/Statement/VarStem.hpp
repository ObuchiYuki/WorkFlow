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

namespace wf {namespace ast{

class VarStem: public Node {
public:
    var target() -> NodePtr;
    var init() -> NodePtr;
            
    VarStem(std::vector<NodePtr> _children, Location _location);
            
    var description() -> std::string const override;
        
    auto eval(wf::run::Environment& env) -> wf::run::Value override;
};

}}


#endif /* VarStem_h */