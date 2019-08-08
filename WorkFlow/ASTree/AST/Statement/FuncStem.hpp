//
//  FuncStem.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/08.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef FuncStem_hpp
#define FuncStem_hpp

#include "Node.hpp"
#include "ParameterList.hpp"
#include "Statement.hpp"

namespace wf {namespace ast{

class FuncStem: public Node {
public:
    var name() const -> std::string;
    var parameters() const -> NodePtr;
    var body() const -> NodePtr;
    
    FuncStem(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {};
    
    var description() -> std::string const override {
        return "(def " + name() + parameters()->description() + body()->description() + ")";
    }
    
};

}}

#endif /* FuncStem_hpp */