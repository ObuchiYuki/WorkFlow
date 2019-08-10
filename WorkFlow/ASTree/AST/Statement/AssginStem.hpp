//
//  AssginStem.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef AssginStem_hpp
#define AssginStem_hpp

#include "Node.hpp"


namespace wf {namespace ast {

    class AssginStem: public Node {
    public:
        
        // MARK: - Propertires -
        var target() const -> NodePtr;
        var value() const -> NodePtr;
        
        // MARK: - Constructor -
        AssginStem(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {}
        
        // MARK: - Methods -
        auto description() const -> std::string override;

        auto eval(wf::run::EnvironmentPtr env) const -> wf::run::Value override;
        
    };

}}


#endif /* AssginStem_hpp */
