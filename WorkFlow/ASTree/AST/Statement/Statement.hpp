//
//  Statement.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/31.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Statement_h
#define Statement_h

#include "../Node/Node.hpp"

#include <sstream>

namespace wf {namespace ast {
    
    class IfStem:public Node {
    public:
        auto condition() -> NodePtr {
            return children[0];
        }
        auto block() -> NodePtr {
            return children[1];
        }
        
        auto description() -> std::string const override {
            return "(if " + condition()->description() + " " + block()->description() + ")";
        }
        
        
        IfStem(std::vector<NodePtr> _children, Location _location) :
        Node(_children, _location) {}
    };

    class BlockStmnt: public Node {
    public:
        
        BlockStmnt(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {};
        
        auto description() -> std::string const override {
            var sstr = std::stringstream();
        
            sstr << "(";
            
            for (let &statement: children){
                sstr << statement->children[0]->children[0]->description();
                sstr << " ";
            }
            
            sstr << ")";
            
            return sstr.str();
        }
    };

}}


#endif /* Statement_h */
