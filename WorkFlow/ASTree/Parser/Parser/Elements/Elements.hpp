//
//  ParserElements.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/31.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef ParserElements_h
#define ParserElements_h

#include <vector>
#include <string>

#include <unordered_map>

#include "rmkit.h"
#include "Parser.hpp"
#include "Lexer.hpp"


namespace wf {

    /// 登録されたパーサーの中からマッチするものを探します。
    class OrElement: public Element{
    private:
        std::vector<_ParserPtr> parsers;
    
    public:
                   
        OrElement(std::vector<_ParserPtr> _parsers);
               
        auto match(Lexer& lexer, int gap) -> bool const override;
        auto parse(Lexer& lexer, std::vector<NodePtr>& res) -> void const override;
        auto rstride(Lexer& lexer, int gap) -> int const override;
        
        
    };

    /// 登録されたパーサーに複数回マッチするかを調べます。
    class RepeatElement: public Element{
    private:
        _ParserPtr parser;
        bool isOptional;
    public:
        RepeatElement(_ParserPtr _parser, bool _once);
        
        auto match(Lexer& lexer, int gap) -> bool const override;
        auto parse(Lexer& lexer, std::vector<NodePtr>& res) -> void const override;
        auto rstride(Lexer& lexer, int gap) -> int const override;
    };

    /// 指定されたTokenを読み飛ばします。
    class SkipElement: public Element{
    private:
        std::vector<std::string> skipTokens;
               
    public:
        SkipElement(std::string _skipToken);
        SkipElement(std::vector<std::string> _skipTokens);

        auto match(Lexer& lexer, int gap) -> bool const override;
        auto parse(Lexer& lexer, std::vector<NodePtr>& res) -> void const override;
        auto rstride(Lexer& lexer, int gap) -> int const override;
        
    };

    /// 指定された構文木をパーサー以下に追加します。
    class TreeElement: public Element {
        _ParserPtr parser;
    public:
        TreeElement(_ParserPtr _parser);
        
        auto match(Lexer& lexer, int gap) -> bool const override;
        auto parse(Lexer& lexer, std::vector<NodePtr>& res) -> void const override;
        auto rstride(Lexer& lexer, int gap) -> int const override;
        
    };
    
    class Precedence {
    public:
        int value;
        bool leftAssoc;  // left associative
        Precedence(int v, bool a) : value(v), leftAssoc(a) {};
    };
    
    typedef std::shared_ptr<Precedence> PrecedencePtr;
    
    enum class Associative {
        RIGHT, LEFT
    };

    class Operator {
    public:
        std::string name;
        Associative associative;
        
        int priority;
        
        Operator(std::string _name, int prec, Associative assoc) :
        name(_name), priority(prec), associative(assoc)
        {}
        
    };
    class Operators {
        std::unordered_map<std::string, PrecedencePtr> map;
        
    public:
        Operators(){}
        Operators(std::vector<Operator> operators) {
            for (let &op: operators) {
                map[op.name] = PrecedencePtr(new Precedence(op.priority, (op.associative == Associative::LEFT)));
            }
        }
        
        PrecedencePtr get(std::string name) {
            return map[name];
        }
        void add(std::string name, int prec, Associative assoc) {
            map[name] = PrecedencePtr(new Precedence(prec, (assoc == Associative::LEFT)));
        }
        bool match(std::string name) const {
            auto itr = map.find(name);
            return itr != map.end();
        }
    };

    
    class ExprElement: public Element {
    public:
        ExprElement(_ParserPtr exp, Operators map);
    
        auto match(Lexer& lexer, int gap) -> bool const override;
        auto parse(Lexer& lexer, std::vector<NodePtr>& res) -> void const override;
        auto rstride(Lexer& lexer, int gap) -> int const override;
        
    private:
        Operators ops;
        _ParserPtr factor;
        
        NodePtr doShift(Lexer& lexer, NodePtr left, int prec);
        
        PrecedencePtr nextOperator(Lexer& lexer);
        
        bool rightIsExpr(int prec, PrecedencePtr nextPrec);
    };

}

#endif /* ParserElements_h */
