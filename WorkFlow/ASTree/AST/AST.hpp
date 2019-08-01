//
//  AST.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef AST_h
#define AST_h

#include <memory>

#include "Node/Node.hpp"
#include "PrimaryNode/PrimaryNode.hpp"

#include "Expression.hpp"
#include "Statement.hpp"

namespace wf {
    namespace ast {
        // ====================================================================== //
        // MARK: - Type Structure Definitions -
        
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
    }
}


#endif /* AST_h */
