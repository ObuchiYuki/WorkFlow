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


namespace wf {namespace ast {
    class VarStem: public Node {
    public:
        var target() -> NodePtr {
            return children[0];
        }
        var init() -> NodePtr {
            return children[1];
        }
            
        VarStem(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {};
            
        auto description() -> std::string const override {
            return "(def " + target()->description() + " = " + init()->description() + ")";
        }
    };
    
    class IfStem:public Node {
    public:
        auto condition() -> NodePtr;
        auto block() -> NodePtr;
        
        auto elseBlock() -> NodePtr;
        
        auto description() -> std::string const override;
        
        IfStem(std::vector<NodePtr> _children, Location _location);
        
        auto eval(wf::run::Environment env) -> Value override;
    };

    class BlockStem: public Node {
    public:
        
        BlockStem(std::vector<NodePtr> _children, Location _location);
        
        auto description() -> std::string const override;
    };
    
    class WhileStem: public Node {
    public:
        
        auto condition() -> NodePtr;
        auto block() -> NodePtr;
        
        WhileStem(std::vector<NodePtr> _children, Location _location);
        
        auto description() -> std::string const override;
    };

}}


#endif /* Statement_h */
