//
//  NullStem.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef NullStem_h
#define NullStem_h

#include "Node.hpp"
#include "Location.hpp"
#include "Lexer.hpp"


namespace wf {namespace ast{

class NullStem: public Node {
public:
    NullStem(std::vector<NodePtr> _children, Location _location) :
    Node(_children, _location) {}
    
    auto description() const -> std::string override {
        return "[NullStem]";
    }
    
};


}}

#endif /* NullStem_h */
