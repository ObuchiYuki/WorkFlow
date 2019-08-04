//
//  Calling.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/04.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Calling_h
#define Calling_h

#include "Expression.hpp"

namespace wf {namespace ast{

class Calling: public Expression {
public:
    auto target() -> NodePtr;
    auto args() -> NodePtr;
    
    Calling(std::vector<NodePtr> _children, Location _location);
        
    auto description() -> std::string const override;
    
    auto eval(wf::run::Environment& env) -> wf::run::Value override;
};


}}
#endif /* Calling_h */
