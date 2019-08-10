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
    
    auto arguments() const -> std::vector<std::shared_ptr<Argument>>;
    
    auto arg(int index) const -> std::shared_ptr<Argument>;
    
    ArgumentList(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {}
    
    auto eval(wf::run::EnvironmentPtr env) const -> wf::run::Value override;
};


}}

#endif /* ArgumentList_hpp */
