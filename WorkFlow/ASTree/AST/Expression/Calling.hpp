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
#include "ArgumentList.hpp"

namespace wf {namespace ast{

class Calling: public Expression {
public:
    var target() const -> NodePtr;
    var args() const -> std::shared_ptr<ArgumentList>;
    
    Calling(std::vector<NodePtr> _children, Location _location);
        
    auto description() const -> std::string override;
    
    auto eval(wf::run::Environment& env) const -> wf::run::Value override;
};


}}
#endif /* Calling_h */
