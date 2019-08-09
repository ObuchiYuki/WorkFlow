//
//  ExAssign.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef ExAssign_hpp
#define ExAssign_hpp

#include "Node.hpp"

namespace wf {namespace ast {

class AddAssignStem: public Node {
public:
    // MARK: - Properties -
    
    var target() const -> NodePtr;
    var value() const -> NodePtr;
    
    var description() const -> std::string override;
    
    // MARK: - Constructor -
    AddAssignStem(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {};

    // MARK: - Methods -

    auto eval(wf::run::Environment& env) const -> wf::run::Value override;
};


class DecAssignStem: public Node {
public:
    // MARK: - Properties -
    
    var target() const -> NodePtr;
    var value() const -> NodePtr;
    
    var description() const -> std::string override;
    
    // MARK: - Constructor -
    DecAssignStem(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {};

    // MARK: - Methods -

    auto eval(wf::run::Environment& env) const -> wf::run::Value override;
};

}}

#endif /* ExAssign_hpp */
