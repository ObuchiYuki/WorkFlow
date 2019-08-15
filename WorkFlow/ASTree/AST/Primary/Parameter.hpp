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
    var label() const -> std::string;
    
    var name() const -> std::string;
    
    Parameter(std::vector<wf::ast::NodePtr> children, wf::Location _location):
    Node(children, _location) {};

    var description() const -> std::string override;
};

}}

#endif /* Parameter_hpp */
