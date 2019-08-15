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
#include "Argument.hpp"

namespace wf {namespace ast{

class ArgumentList: public Node {
public:
    var numArgument() const -> int;
    
    auto arguments() const -> rm::vector<std::shared_ptr<Argument>>;
    auto argumentTypes(type::TypeEnvironment &env) const -> std::vector<type::TypePtr>;
    
    auto arg(int index) const -> std::shared_ptr<Argument>;
    
    ArgumentList(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {}
        
    var description() const -> std::string override{
        return "(" + rm::description::join(arguments(), ", ", [](auto e){return e->description();}) + ")";
    }
};


}}

#endif /* ArgumentList_hpp */
