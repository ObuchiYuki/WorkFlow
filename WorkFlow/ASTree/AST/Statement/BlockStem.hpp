//
//  BlockStem.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef BlockStem_h
#define BlockStem_h

#include <string>
#include <vector>

#include "location.hpp"
#include "Environment.hpp"
#include "Node.hpp"

namespace wf {namespace ast {
    

class BlockStem: public Node {
public:
        
    BlockStem(std::vector<NodePtr> _children, Location _location);
        
    auto description() -> std::string const override;
        
    wf::run::Value eval(wf::run::Environment &env) override;
};


}}


#endif /* BlockStem_h */
