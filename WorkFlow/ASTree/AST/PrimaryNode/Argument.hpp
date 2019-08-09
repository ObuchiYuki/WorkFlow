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

namespace wf {namespace ast {

class Argument: public Node {
public:
    Argument(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {}
    
    auto eval(wf::run::Environment& env) const -> wf::run::Value override;
};


}}

#endif /* Arguments_hpp */
