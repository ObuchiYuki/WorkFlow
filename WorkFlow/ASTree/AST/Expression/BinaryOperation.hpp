//
//  BinaryOperation.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef BinaryOperation_hpp
#define BinaryOperation_hpp

#include "Node.hpp"

namespace wf { namespace ast {

class BinaryOperation: public Node {
public:
    auto left() const -> NodePtr;
    auto right() const -> NodePtr;
    
    auto op() const -> NodePtr;
            
    BinaryOperation(std::vector<NodePtr> _children, Location _location);
    
    var description() const -> std::string override;
    auto eval(wf::run::EnvironmentPtr env) const -> wf::run::Value override;
};

}}

#endif /* BinaryOperation_hpp */
