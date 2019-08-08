//
//  ParameterList.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/08.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef ParameterList_hpp
#define ParameterList_hpp

#include "Node.hpp"

namespace wf {namespace ast {
    
class ParameterList: public Node {
public:
    ParameterList(std::vector<NodePtr> _children, Location _location) :
       Node(_children, _location) {}
                
    std::string name(int i) {
        return nodeAsLeaf(children[i])->token->value;
    }
};


}}

#endif /* ParameterList_hpp */
