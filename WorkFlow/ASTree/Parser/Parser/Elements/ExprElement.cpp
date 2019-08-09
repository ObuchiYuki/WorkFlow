//
//  ExprElement.cpp
//  WorkFlow
//
//  Created by yuki on 2019/07/26.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "Elements.hpp"

#include <vector>
#include <exception>

#include "Token.hpp"
#include "Parser.hpp"
#include "Lexer.hpp"
#include "BinaryOperation.hpp"
#include "WorkFlowError.hpp"

using namespace wf;


namespace wf {

// ====================================================================== //
// MARK: - Private Classes -

// MARK: - Precedence -
/// 演算子の優先順位を保管します。
class Precedence {
public:
    // MARK: - Properties -
    
    /// 演算子の優先順位
    int priority;
    
    /// 左結合かどうか
    bool isLeftAssoc;
    
    // MARK: - Constructor -
    Precedence(int v, bool a) : priority(v), isLeftAssoc(a) {};
};

/// Link for Precedence Ptr
typedef std::shared_ptr<Precedence> PrecedencePtr;

// MARK: - _Operators -
/// 演算子一覧を保存します。
class _Operators {
private:
    /// 演算子と優先順位の対応です。
    std::unordered_map<std::string, PrecedencePtr> map;
    
public:
    // MARK: - Constructor -
    
    /// Operatorsから初期化します。
    _Operators(Operators operators) {
        for (let &op: operators.operators) {
            
            map[op.value] = PrecedencePtr(new Precedence(op.priority, (op.associative == Associative::LEFT)));
        }
    }
    
    // MARK: - Methods -
    /// 演算子名から優先順位を取り出します。
    auto get(std::string name) const -> PrecedencePtr {
        try {
            return map.at(name);
        }catch(std::out_of_range e) {
            throw wf::WorkFlowError("[_Operators::get] operator named " + name + " not found.");
        }
    }
    
    /// 演算子が存在するかを返します。
    auto match(std::string name) const -> const bool {
        
        return map.find(name) != map.end();
    }
};

// MARK: - ExprParser -
/// 実際にパースを行います。
class ExprParser {
    _ParserPtr factor;
    _Operators mutable ops;
    
public:
    ExprParser(_ParserPtr _factor, Operators _ops) : factor(_factor), ops(_ops) {}
    
    auto parse(Lexer& lexer, std::vector<ast::NodePtr>& res) const -> void;
    
    auto doShift(Lexer& lexer, ast::NodePtr left, int prec) const -> ast::NodePtr;
    auto nextOperator(Lexer& lexer) const -> const PrecedencePtr;
    auto rightIsExpr(int prec, PrecedencePtr nextPrec) const -> const bool;
};
}

// ====================================================================== //
// MARK: - ExprParser Impl -
// ====================================================================== //
auto ExprParser::nextOperator(Lexer& lexer) const -> const PrecedencePtr {
    let t = lexer.peek(0);
    
    if (t->type == token::TokenType::OPERATOR) {
        return ops.get(t->value);
    }else{
        return nullptr;
    }
}

auto ExprParser::rightIsExpr(int prec, PrecedencePtr nextPrec) const -> const bool {
    if (nextPrec->isLeftAssoc){
        return prec < nextPrec->priority;
    } else {
        return prec <= nextPrec->priority;
    }
}

auto ExprParser::doShift(Lexer& lexer, ast::NodePtr left, int prec) const -> ast::NodePtr {
    var list = std::vector<ast::NodePtr>();
    
    list.push_back(left);
    let token = lexer.readNext();
    list.push_back(ast::NodePtr(new ast::Operator(token, token->location)));
    
    ast::NodePtr right = factor->parse(lexer);
    
    PrecedencePtr next = nextOperator(lexer);
    
    while (next != nullptr && rightIsExpr(prec, next)) {
        right = doShift(lexer, right, next->priority);
        
        next = nextOperator(lexer);
    }
    
    list.push_back(right);
    
    return ast::NodePtr(new ast::BinaryOperation(list, list.front()->location));
}

auto ExprParser::parse(Lexer& lexer, std::vector<ast::NodePtr>& res) const -> void {
    ast::NodePtr right = factor->parse(lexer);
    PrecedencePtr prec = nextOperator(lexer);
    
    while(prec != nullptr) {
        right = doShift(lexer, right, prec->priority);
        
        prec = nextOperator(lexer);
    }
    
    res.push_back(right);
}

// ====================================================================== //
// MARK: - ExprElement Impl -
// ====================================================================== //

auto ExprElement::parse(Lexer& lexer, std::vector<ast::NodePtr>& res) const -> void {
    let parser = ExprParser(factor, operators);
    
    parser.parse(lexer, res);
}
auto ExprElement::match(Lexer& lexer, int gap) const -> const bool {
    
    return factor->match(lexer, gap);
}

auto ExprElement::rstride(Lexer& lexer, int gap) const -> const int {
    
    auto rstride = 0;
    auto rgap = gap;
    auto repeatFlag = true;
    
    while (repeatFlag) {

        if (factor->match(lexer, rgap)){
            auto a = factor->rstride(lexer, rgap);
            rstride += a;
            rgap += a;
        }else if (operators.match(lexer.peek(rgap)->value)){
             rstride += 1;
             rgap += 1;
        }else{
            repeatFlag = false;
        }
    }
    
    return rstride;
}
    
auto ExprElement::description() const -> const std::string{
    return "[Expr]";
}

