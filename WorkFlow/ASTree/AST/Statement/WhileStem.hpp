//
//  WhileStem.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef WhileStem_h
#define WhileStem_h

#include <string>
#include <vector>

#include "Node.hpp"
#include "location.hpp"
#include "Value.hpp"
#include "Environment.hpp"

namespace wf {namespace ast {

class WhileStem: public Node {
public:
        
    auto condition() -> NodePtr;
    auto block() -> NodePtr;
        
    WhileStem(std::vector<NodePtr> _children, Location _location);
        
    auto description() -> std::string const override;

    wf::run::Value eval(wf::run::Environment &env) override;
};

}}


#endif /* WhileStem_h */
