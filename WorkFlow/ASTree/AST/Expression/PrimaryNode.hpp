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

#include "Location.hpp"
#include "Node.hpp"
#include "Leaf.hpp"
#include "Token.hpp"
#include "WorkFlowError.hpp"

namespace wf { namespace ast{


// MARK: - PrimaryNode -

/// リテラル・識別子などを表すプライマリオブジェクトを表すノードです。
class PrimaryNode : public Leaf {
public:
    PrimaryNode(token::TokenPtr _token, Location _location) : Leaf(_token, _location) {}
            
    virtual ~PrimaryNode() {};
    
    /// 今だけ
    auto eval(wf::run::EnvironmentPtr env) -> wf::run::Value override {
        return wf::run::Value(token->value);
    }
    
    auto description() const -> std::string override {
        return token->value;
    };
};

/// 文字列リテラルを表します。
class StringLiteral: public PrimaryNode {
public:
            
    StringLiteral(token::TokenPtr _token, Location _location) : PrimaryNode(_token, _location) {}
    
    var returnType(wf::type::TypeEnvironment& env) -> wf::type::TypePtr override {
        return type::PrimitiveType::String;
    }
    
    var description() const -> std::string override {
        return "\"" + token->value + "\"";
    };
};


/// 整数リテラルを表します。
class IntegerLiteral: public PrimaryNode {
public:
    auto value() const -> int {
        return std::stoi(token->value);
    }
    
    var returnType(wf::type::TypeEnvironment& env) -> wf::type::TypePtr override {
        return type::PrimitiveType::Int;
    }
    
    /// 今だけ
    auto eval(wf::run::EnvironmentPtr env) -> wf::run::Value override {
        return wf::run::Value(value());
    }
            
    IntegerLiteral(token::TokenPtr _token, Location _location) : PrimaryNode(_token, _location) {}
    
};

/// 不動小数点リテラルを表します。
class FloatLiteral: public PrimaryNode {
public:
    auto value() const -> float {
        return std::stod(token->value);
    }
    
    var returnType(wf::type::TypeEnvironment& env) -> wf::type::TypePtr override {
        return type::PrimitiveType::Float;
    }
            
    FloatLiteral(token::TokenPtr _token, Location _location) : PrimaryNode(_token, _location) {}
    
};

/// コンパイラディレクティブを表します。
class Directive: public PrimaryNode {
public:
    
    Directive(token::TokenPtr _token, Location _location) : PrimaryNode(_token, _location) {}
    
    var description() const -> std::string override {
        return "@" + token->value;
    };
};

class Operator: public PrimaryNode {
public:
            
    Operator(token::TokenPtr _token, Location _location) : PrimaryNode(_token, _location) {}
};

class Name: public PrimaryNode {
public:
    
    var returnType(wf::type::TypeEnvironment& env) -> wf::type::TypePtr override {
        let name = token->value;
        let type = env.getType(name);
        
        if (!type) {
            throw WorkFlowError("Variable named " + name + " is not defined.");
        }
        
        return type;
    }
    
    /// 今だけ
    auto eval(wf::run::EnvironmentPtr env) -> wf::run::Value override {
        return env->get(token->value);
    }
    
    Name(token::TokenPtr _token, Location _location) : PrimaryNode(_token, _location) {}
};


}}

#endif /* PrimaryNode_h */
