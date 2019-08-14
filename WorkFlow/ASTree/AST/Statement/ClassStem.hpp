//
//  ClassStem.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/14.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef ClassStem_hpp
#define ClassStem_hpp

#include "Node.hpp"
#include "Leaf.hpp"

namespace wf {namespace ast {

class ClassStem: public Node {
public:
    var classname() const -> std::string {
        
        return nodeAsLeaf(children[0])->token->value;
    }
    var classBody() const -> NodePtr {
        return children[1];
    }
    
    ClassStem(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {};
    
    var description() const -> std::string override {
        return "(class " + classname() + classBody()->description() + ")";
    }
    
    auto eval(wf::run::EnvironmentPtr env) const -> wf::run::Value override {
        return wf::run::Value::voidValue();
    }
    
};

}}

#endif /* ClassStem_hpp */
