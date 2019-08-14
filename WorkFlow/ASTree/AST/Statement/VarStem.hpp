//
//  VarStem.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef VarStem_h
#define VarStem_h

#include <string>

#include "location.hpp"
#include "Environment.hpp"
#include "Node.hpp"
#include "TypeSpecifier.hpp"

namespace wf {namespace ast{

class VarStem: public Node {
public:
    var target() const -> std::string;
    var typeSpecifier() const -> std::shared_ptr<TypeSpecifier>;
    var init() const -> NodePtr;
            
    VarStem(std::vector<NodePtr> _children, Location _location);
            
    var description() const -> std::string override;
        
    auto eval(wf::run::EnvironmentPtr env) const -> wf::run::Value override;
};

}}


#endif /* VarStem_h */
