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
#include "Type.hpp"
#include "Expression.hpp"

namespace wf {namespace ast{

/**
 def i = 1
 iの方は常に自動で予測する
 */
class VarStem: public Node {
public:
    var valueType() const -> type::TypePtr;
    
    var target() const -> std::string;
    var init() const -> ExpressionPtr;
            
    VarStem(std::vector<NodePtr> _children, Location _location);
    
    var description() const -> std::string override;
        
};

}}


#endif /* VarStem_h */
