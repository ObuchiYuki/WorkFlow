//
//  Parameter.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/10.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Parameter_hpp
#define Parameter_hpp Node

#include "Node.hpp"
#include "Leaf.hpp"

namespace wf {namespace ast{

class Parameter: public Node {
public:
    var label() -> std::string {
        return nodeAsLeaf(children[0])->token->value;
    }
    
    var name() -> std::string {
        return nodeAsLeaf(children[1])->token->value;
    }
    
    Parameter(std::vector<wf::ast::NodePtr> children, wf::Location _location):
    Node(children, _location) {};

    
};

}}

#endif /* Parameter_hpp */
