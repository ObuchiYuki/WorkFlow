//
//  Node.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/22.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <vector>
#include <memory>

#include "rmkit.h"
#include "TypeUmbrella.hpp"

#include "Lexer.hpp"
#include "Location.hpp"

namespace wf {namespace ast {
    
// ====================================================================== //
// MARK: - Type Definitions -

       
class Node;
class Leaf;
    
typedef std::shared_ptr<Leaf> LeafPtr;
typedef std::shared_ptr<Node> NodePtr;
    
// ====================================================================== //
// MARK: - Type Structure Definitions -

class Node  {
public:
    // MARK: - Properties -
    /// 子ノードです。
    std::vector<std::shared_ptr<Node>> children;
            
    /// ノードの場所です。
    const Location location;
        
    // MARK: - Methods -
            
    auto appendChild(std::shared_ptr<Node> child) -> void;
    auto numChildren() const -> int;
    
    virtual auto typeRegister(type::TypePtr type) -> void;
    virtual auto typeCheck(type::TypeEnvironment& env) -> void;
    
    virtual var description() const -> std::string;
    
    // MARK: - Constructor -
    Node(std::vector<std::shared_ptr<Node>> _children, Location _location);

    virtual ~Node() {};
    
};

typedef std::shared_ptr<Node> NodePtr;
    
}}

#endif /* Node_hpp */


