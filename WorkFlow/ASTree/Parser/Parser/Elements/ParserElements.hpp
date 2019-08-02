//
//  ParserElements.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/31.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef ParserElements_h
#define ParserElements_h

#include <unordered_map>

namespace wf {
    /// 登録されたパーサーの中からマッチするものを探します。
    class OrElement: public Element{
    private:
        std::vector<_ParserPtr> parsers;
        
        auto chooseParser(Lexer& lexer) -> rm::optional<_ParserPtr> const;
    public:
                   
        OrElement(std::vector<_ParserPtr> _parsers);
               
        auto match(Lexer& lexer) -> bool const override;
        auto parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const override;
    };

    /// 登録されたパーサーに複数回マッチするかを調べます。
    class RepeatElement: public Element{
    private:
        _ParserPtr parser;
        bool once;
    public:
        RepeatElement(_ParserPtr _parser, bool _once);
                          
        auto match(Lexer& lexer) -> bool const override;
        auto parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const override;
    };

    /// 指定されたTokenを読み飛ばします。
    class SkipElement: public Element{
    private:
        std::vector<std::string> skipTokens;
               
    public:
        SkipElement(std::string _skipToken);
        SkipElement(std::vector<std::string> _skipTokens);
                          
        auto match(Lexer& lexer) -> bool const override;
        auto parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const override;
    };

    /// 指定された構文木をパーサー以下に追加します。
    class TreeElement: public Element {
        _ParserPtr parser;
    public:
        TreeElement(_ParserPtr _parser);
                   
        auto parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const override;
        auto match(Lexer& lexer) -> bool const override;
        
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
    
    class Operators {
        std::unordered_map<std::string, PrecedencePtr> map;
        
    public:
        PrecedencePtr get(std::string name) {
            return map[name];
        }
        void add(std::string name, int prec, Associative assoc) {
            map[name] = PrecedencePtr(new Precedence(prec, (assoc == Associative::LEFT)));
        }
    };

    
    class ExprElement: public Element {
    public:
        ExprElement(_ParserPtr exp, Operators map);
        
        auto parse(Lexer& lexer, std::vector<NodePtr>& res) -> void const override;
        
        auto match(Lexer& lexer) -> bool const override;
        
    private:
        Operators ops;
        _ParserPtr factor;
        
        NodePtr doShift(Lexer& lexer, NodePtr left, int prec);
        
        PrecedencePtr nextOperator(Lexer& lexer);
        
        bool rightIsExpr(int prec, PrecedencePtr nextPrec);
    };

}

#endif /* ParserElements_h */
