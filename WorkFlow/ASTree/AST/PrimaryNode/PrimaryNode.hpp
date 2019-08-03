//
//  PrimaryNode.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/30.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef PrimaryNode_h
#define PrimaryNode_h

#include <string>
#include <memory>
#include <vector>

#include "location.hpp"
#include "Node.hpp"

namespace wf { namespace ast{


// MARK: - PrimaryNode -

/// リテラル・識別子などを表すプライマリオブジェクトを表すノードです。
class PrimaryNode : public Leaf {
public:     
    PrimaryNode(std::vector<NodePtr> _children, Location _location);
            
    virtual ~PrimaryNode();
    
    auto description() -> const std::string override;
};

/// 文字列リテラルを表します。
class StringLiteral: public PrimaryNode {
public:
    auto value() -> std::string const;
            
    StringLiteral(std::vector<NodePtr> _children, Location _location);
};


/// 整数リテラルを表します。
class IntegerLiteral: public PrimaryNode {
public:
    auto value() -> int const;
            
    IntegerLiteral(std::vector<NodePtr> _children, Location _location);
};

/// 不動小数点リテラルを表します。
class FloatLiteral: public PrimaryNode {
public:
    auto value() -> float const;
            
    FloatLiteral(std::vector<NodePtr> _children, Location _location);
    
};

/// コンパイラディレクティブを表します。
class Directive: public PrimaryNode {
public:
    auto value() -> std::string const;
            
    Directive(std::vector<NodePtr> _children, Location _location);
    
};

class Operator: public PrimaryNode {
public:
    auto value() -> std::string  const;
            
    Operator(std::vector<NodePtr> _children, Location _location);
    
};

class Name: public PrimaryNode {
public:
        
    auto value() -> std::string const;
            
    Name(std::vector<NodePtr> _children, Location _location);
    
};


}}
#endif /* PrimaryNode_h */
