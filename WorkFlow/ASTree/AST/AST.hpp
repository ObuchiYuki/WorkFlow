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

#include "BinaryOperation.hpp"

namespace wf {
    namespace ast {
        // ====================================================================== //
        // MARK: - Type Structure Definitions -
        
        class Expression: public Node {
        public:
            Expression(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {};
            
            auto description() ->  std::string const override;
        };
        
        class VarStem: public Node {
        public:
            var target() -> std::shared_ptr<Name> {
                return std::dynamic_pointer_cast<Name>(children[0]);
            }
            var init() -> std::shared_ptr<Expression> {
                return std::dynamic_pointer_cast<Expression>(children[1]);
            }
            
            VarStem(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {};
            
            auto description() -> std::string const override {
                return "(def " + target()->description() + " = " + init()->description() + ")";
            }
        };
        
        class NegativeExpr: public Node {
        public:
            NegativeExpr(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {};
        };
    
        class BlockStmnt: public Node {
        public:
            BlockStmnt(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {};
        };
    }
}


#endif /* AST_h */
