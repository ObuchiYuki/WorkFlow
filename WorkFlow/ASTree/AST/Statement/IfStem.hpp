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

#include "location.hpp"
#include "Environment.hpp"
#include "Node.hpp"

namespace wf {namespace ast{


class IfStem:public Node {
public:
    auto condition() -> NodePtr;
    auto block() -> NodePtr;
        
    auto elseBlock() -> NodePtr;
        
    auto description() -> std::string const override;
        
    IfStem(std::vector<NodePtr> _children, Location _location);
        
    auto eval(wf::run::Environment& env) -> wf::run::Value override;
};

}}


#endif /* IfStem_h */
