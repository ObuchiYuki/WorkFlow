//
//  ParameterList.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/08.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef ParameterList_hpp
#define ParameterList_hpp

#include <vector>
#include <memory>
#include <string>

#include "Node.hpp"
#include "Leaf.hpp"
#include "Parameter.hpp"

namespace wf {namespace ast {
    
class ParameterList: public Node {
public:
    ParameterList(std::vector<NodePtr> _children, Location _location) :
       Node(_children, _location) {}
            
    
    var allParamaters() -> std::vector<std::shared_ptr<wf::ast::Parameter>> {
        var dec = std::vector<std::shared_ptr<wf::ast::Parameter>>(numParamaters());
        for (let& child: children) {
            dec.push_back(std::dynamic_pointer_cast<wf::ast::Parameter>(child));
        }
        return dec;
    }
    
    var numParamaters() -> int {
        return static_cast<int>(children.size());
    }
    
    var paramater(int i) const -> std::shared_ptr<wf::ast::Parameter> {
        return std::dynamic_pointer_cast<wf::ast::Parameter>(children[i]);
    }
    var name(int i) const -> std::string {
        return paramater(i)->name();
    }
    var label(int i) const -> std::string{
        return paramater(i)->label();
    }
    
};


}}

#endif /* ParameterList_hpp */
