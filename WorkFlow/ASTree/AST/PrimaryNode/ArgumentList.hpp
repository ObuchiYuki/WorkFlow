//
//  ArgumentList.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef ArgumentList_hpp
#define ArgumentList_hpp

#include "Node.hpp"

namespace wf {namespace ast{

class ArgumentList: public Node {
public:
    auto arg(int index) const -> NodePtr;
    
    ArgumentList(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {}
    
    auto eval(wf::run::Environment& env) const -> wf::run::Value override;
};


}}

#endif /* ArgumentList_hpp */
