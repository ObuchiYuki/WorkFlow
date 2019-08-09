//
//  Leaf.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Leaf_hpp
#define Leaf_hpp


#include <vector>
#include <string>

#include "Node.hpp"

#include "location.hpp"
#include "Environment.hpp"


namespace wf {namespace ast {

/// 子ノードを持たない端のノードを表します。
/// tokenとしての値を持ちます。
class Leaf: public Node {
public:
    // MARK: - Methods -
        
    ///値のトークンです。
    std::shared_ptr<wf::token::Token> token;
            
    Leaf(std::shared_ptr<wf::token::Token> _token, Location _location);
            
    virtual ~Leaf(){}
            
    auto description() const -> std::string override;
    auto eval(wf::run::Environment& env) const -> wf::run::Value override;
};

inline LeafPtr nodeAsLeaf(NodePtr node){
    return std::dynamic_pointer_cast<Leaf>(node);
}

}}

#endif /* Leaf_hpp */
