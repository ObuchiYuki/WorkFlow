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
            
    
    var allParamaters() -> std::vector<std::shared_ptr<wf::ast::Parameter>>;
    
    var numParamaters() -> int;
    
    var paramater(int i) const -> std::shared_ptr<wf::ast::Parameter>;
    var name(int i) const -> std::string;
    var label(int i) const -> std::string;
    
    var description() const -> std::string override;
    
};


}}

#endif /* ParameterList_hpp */
