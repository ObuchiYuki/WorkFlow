//
//  ParserElements.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/31.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef ParserElements_h
#define ParserElements_h

namespace wf {
    /// 登録されたパーサーの中からマッチするものを探します。
    class OrElement: public Element{
    private:
        std::vector<_ParserPtr> parsers;
        
        auto chooseParser(Lexer& lexer) -> optinal<_ParserPtr> const;
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
        std::string skipToken;
               
    public:
        SkipElement(std::string _skipToken);
                          
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
    
    /// 指定された構文木をパーサー以下に追加します。
    class ExprElement: public Element {
        _ParserPtr factor;
    public:
               
              
        ExprElement(_ParserPtr _parser);
        
        auto shiftNext(Lexer& lexer) -> Element;
               
        auto parse(Lexer& lexer, std::vector<NodePtr> &res) -> void const override;
        auto match(Lexer& lexer) -> bool const override;
        
    };
}

#endif /* ParserElements_h */
