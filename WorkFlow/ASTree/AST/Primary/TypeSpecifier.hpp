//
//  TypeSpecifier.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/12.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef TypeSpecifier_hpp
#define TypeSpecifier_hpp

#include <string>

#include "Node.hpp"
#include "Type.hpp"


namespace wf {namespace ast{

class TypeSpecifier: public Node {
public:
    var type() const -> type::TypePtr;
    
    TypeSpecifier(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {}
    
    std::string description() const override {
        return type()->description() + ":";
    }
    
};

}}

#endif /* TypeSpecifier_hpp */
