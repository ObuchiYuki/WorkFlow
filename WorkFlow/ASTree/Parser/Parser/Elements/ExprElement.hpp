//
//  ExprElement.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/07.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef ExprElement_h
#define ExprElement_h

#include "Lexer.hpp"
#include "Parser.hpp"
#include "Element.hpp"
#include "Parser_umbrella.hpp"

namespace wf {

/// 結合の方向を表します。
enum class Associative {
    RIGHT, LEFT
};

/// 演算子の情報を保存します。
class Operator {
public:
    
    /// 演算子名
    const std::string value;
    
    /// 演算子の優先度
    const int priority;
    
    /// 演算子の結合方向
    const Associative associative;

    // MARK: - Constructor -
    Operator(const std::string _value, const int _priority, const Associative _associative) :
    value(_value), priority(_priority), associative(_associative)
    {}
};

/// 演算子をまとめて表します。
class Operators {
public:
    
    /// 演算子
    std::vector<Operator> operators;
    
    // MARK: - Methods -
    
    /// 演算子が存在するかを返します。
    auto match(std::string value) const -> const bool {
        for (let &op: operators){
            if (op.value == value) return true;
        }
        return false;
    }
    
    // MARK: - Constructor -
    Operators(std::vector<Operator> _operators) : operators(_operators) {}

};

/// 式を評価します。
class ExprElement: public Element {
private:
    
    Operators operators;
    _ParserPtr factor;
public:
    ExprElement(_ParserPtr _factor, Operators _operators) : factor(_factor), operators(_operators) {}

    auto parse(Lexer& lexer, std::vector<ast::NodePtr>& res) const -> void override;
    auto match(Lexer& lexer, int gap) const -> const bool override;
    auto rstride(Lexer& lexer, int gap) const -> const int override;
    
    auto description() const -> const std::string override;
    
};

}

#endif /* ExprElement_h */
