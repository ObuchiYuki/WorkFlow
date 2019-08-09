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
        
    auto condition() const -> NodePtr;
    auto block() const -> NodePtr;
        
    WhileStem(std::vector<NodePtr> _children, Location _location);
        
    auto description() const -> std::string override;

    auto eval(wf::run::Environment &env) const -> wf::run::Value override;
};

}}


#endif /* WhileStem_h */
