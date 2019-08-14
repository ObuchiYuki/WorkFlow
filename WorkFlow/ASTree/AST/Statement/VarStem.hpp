//
//  varStem.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef varStem_h
#define varStem_h

#include <string>

#include "location.hpp"
#include "Environment.hpp"
#include "Node.hpp"
#include "TypeSpecifier.hpp"

namespace wf {namespace ast{

class varStem: public Node {
public:
    var target() const -> std::string;
    var typeSpecifier() const -> std::shared_ptr<TypeSpecifier>;
    var init() const -> NodePtr;
            
    varStem(std::vector<NodePtr> _children, Location _location);
            
    var description() const -> std::string override;
        
    auto eval(wf::run::EnvironmentPtr env) const -> wf::run::Value override;
};

}}


#endif /* varStem_h */
