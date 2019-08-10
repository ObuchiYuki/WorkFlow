//
//  ParameterList.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/10.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "ParameterList.hpp"

using namespace wf::ast;
    

var ParameterList::allParamaters() -> std::vector<std::shared_ptr<wf::ast::Parameter>> {
    var dec = std::vector<std::shared_ptr<wf::ast::Parameter>>(numParamaters());
    
    for (let& child: children) {
        dec.push_back(std::dynamic_pointer_cast<wf::ast::Parameter>(child));
    }
    return dec;
}

var ParameterList::numParamaters() -> int {
    return static_cast<int>(children.size());
}

var ParameterList::paramater(int i) const -> std::shared_ptr<wf::ast::Parameter> {
    return std::dynamic_pointer_cast<wf::ast::Parameter>(children[i]);
}

var ParameterList::name(int i) const -> std::string {
    return paramater(i)->name();
}

var ParameterList::label(int i) const -> std::string{
    return paramater(i)->label();
}

var ParameterList::description() const -> std::string {
    return "(" + rm::description::join(children, ", ", [](auto e){return e->description();}) + ")";
}
