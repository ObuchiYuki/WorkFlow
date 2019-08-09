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
#include "Token.hpp"
#include "WorkFlowError.hpp"

namespace wf { namespace ast{


// MARK: - PrimaryNode -

/// リテラル・識別子などを表すプライマリオブジェクトを表すノードです。
class PrimaryNode : public Leaf {
public:
    PrimaryNode(token::TokenPtr _token, Location _location) : Leaf(_token, _location) {}
            
    virtual ~PrimaryNode() {};
    
    auto description() -> const std::string override {
        return token->value;
    };
};

/// 文字列リテラルを表します。
class StringLiteral: public PrimaryNode {
public:
            
    StringLiteral(token::TokenPtr _token, Location _location) : PrimaryNode(_token, _location) {}
};


/// 整数リテラルを表します。
class IntegerLiteral: public PrimaryNode {
public:
    auto value() -> int const {
        return std::stoi(token->value);
    }
            
    IntegerLiteral(token::TokenPtr _token, Location _location) : PrimaryNode(_token, _location) {}
    
    wf::run::Value eval(wf::run::Environment& env) override {
        return wf::run::Value(value());
    }
};

/// 不動小数点リテラルを表します。
class FloatLiteral: public PrimaryNode {
public:
    auto value() -> float const {
        return std::stod(token->value);
    }
            
    FloatLiteral(token::TokenPtr _token, Location _location) : PrimaryNode(_token, _location) {}
    
    wf::run::Value eval(wf::run::Environment& env) override {
        return wf::run::Value(value());
    }
};

/// コンパイラディレクティブを表します。
class Directive: public PrimaryNode {
public:
    
    Directive(token::TokenPtr _token, Location _location) : PrimaryNode(_token, _location) {}
};

class Operator: public PrimaryNode {
public:
            
    Operator(token::TokenPtr _token, Location _location) : PrimaryNode(_token, _location) {}
};

class Name: public PrimaryNode {
public:
            
    Name(token::TokenPtr _token, Location _location) : PrimaryNode(_token, _location) {}
    
    auto eval(wf::run::Environment& env) -> wf::run::Value override {
        try {
            return env.get(token->value);
        } catch (std::out_of_range e) {
            throw wf::WorkFlowError("Variable named '" + token->value + "' is not defined.");
        }
        
    }
};


}}

#endif /* PrimaryNode_h */
