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

#include "Lexer.hpp"
#include "location.hpp"
#include "Environment.hpp"

namespace wf {namespace ast {
    
// ====================================================================== //
// MARK: - Type Definitions -

       
class Node;
class Leaf;
    
typedef std::shared_ptr<Leaf> LeafPtr;
typedef std::shared_ptr<Node> NodePtr;
    
// ====================================================================== //
// MARK: - Type Structure Definitions -

/// evalの実行に使用される値です。
class Value {
private:
    rm::any _value;
public:
    Value(rm::any __value): _value(__value) {};
    
    static auto voidValue() -> Value {
        return Value(nil);
    }
    
    int integer() const {
        return _value.as<int>();
    }
    std::string string() const{
        return _value.as<std::string>();
    }
    bool boolean() const{
        return _value.as<bool>();
    }
    float floating() const{
        return _value.as<float>();
    }
    
    friend std::ostream& operator << (std::ostream &os, const Value a) {
        os << a._value;
        
        return os;
    }
};
            


class Node  {
public:
    // MARK: - Properties -
    /// 子ノードです。
    std::vector<std::shared_ptr<Node>> children;
            
    /// ノードの場所です。
    Location location;
        
    // MARK: - Methods -
            
    auto appendChild(std::shared_ptr<Node> child) -> void;
    auto numChildren() -> int;
            
    virtual auto description() -> const std::string;
    virtual auto eval(wf::run::Environment env) -> Value;
    
    // MARK: - Constructor -
    Node(std::vector<std::shared_ptr<Node>> _children, Location _location);

    virtual ~Node() {};
    
};

typedef std::shared_ptr<Node> NodePtr;

/// 子ノードを持たない端のノードを表します。
/// tokenとしての値を持ちます。
class Leaf: public Node {
public:
    // MARK: - Methods -
        
    ///値のトークンです。
    std::shared_ptr<wf::token::Token> token;
            
    Leaf(std::shared_ptr<wf::token::Token> _token, Location _location);
            
    virtual ~Leaf(){}
            
    auto description() -> const std::string override;
    auto eval(wf::run::Environment env) -> Value override;
};

inline LeafPtr nodeAsLeaf(NodePtr node){
    return std::dynamic_pointer_cast<Leaf>(node);
}
    
}}

#endif /* Node_hpp */


