//
//  Parser.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/25.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Parser_h
#define Parser_h

#include <memory>
#include <vector>

#include "Node.hpp"
#include "Lexer.hpp"
#include "AST.hpp"


namespace wf {
    // ====================================================================== //
    // MARK: - Type Definitions -
    template<class T> class _Parser;
    class _AnyParser;
    class Element;
    class Accessor;

    // ==================================== //
    // MARK: - Type Linking -
    typedef std::shared_ptr<_AnyParser>    _ParserPtr;
    typedef std::shared_ptr<Element>       ElementPtr;
    typedef std::shared_ptr<ast::Node>     NodePtr;
    typedef std::shared_ptr<ast::Leaf>     LeafPtr;
    typedef std::shared_ptr<Accessor>      AccessorPtr;
    
    // ====================================================================== //
    // MARK: - Type Structure Definitions -

    // MARK: - Basic Classes -

    /// パーサーが実際にパースする際の行動を決定します。
    /// Elementを継承して、match、parseを失踪してください。
    class Element{
    public:
               
        virtual auto match(Lexer& lexer) -> bool const = 0;
        virtual auto parse(Lexer& lexer, std::vector<NodePtr>& res) -> void const = 0;
    };
    /// 実際にパースを行います。
    
    // TODO: - Implを分ける -
    template<class T> // T: Access
    class _Parser {
    public:
        virtual ~_Parser() {};
        std::vector<ElementPtr> elements;
                  
        /// Lexer& が Perserにマッチしているかを調べます。
        virtual auto match(Lexer& lexer) -> bool const {
            
            return elements[0]->match(lexer);
        }
                  
        /// Lexerの値を元に実際にパースを行います。
        virtual auto parse(Lexer& lexer) -> std::shared_ptr<T> const {
            std::vector<NodePtr> results = {};
                        
            for (int i=0; i<elements.size();i++) {
                elements[i]->parse(lexer, results);
            }
        
            let node = std::shared_ptr<T>(new T(results, results[0]->location));
            
            return node;
        }
           
        auto addElement(ElementPtr element) -> void{
            
            elements.push_back(element);
        }
    };

    // MARK: - AnyParsr

    namespace anyparser {
        class holder {
        public:
            virtual auto parse(Lexer& lexer) -> NodePtr const = 0;
            virtual auto match(Lexer& lexer) -> bool const = 0;
            virtual auto addElement(ElementPtr element) -> void = 0;
        };

        template<typename T> // T: Parser<S>
        struct holder_sub : public holder {
            std::shared_ptr<T> parser;
            
            holder_sub(std::shared_ptr<T> _parser) : parser(_parser) {};
            
            auto parse(Lexer& lexer) -> NodePtr const override {
                return parser->parse(lexer);
            }
            auto match(Lexer& lexer) -> bool const override {
                return parser->match(lexer);
            }
            auto addElement(ElementPtr element) -> void override {
                parser->addElement(element);
            }
        };
    }

    class _AnyParser {
    public:
        
        std::shared_ptr<anyparser::holder> _holder;
        
        template<typename T>
        _AnyParser(_Parser<T>* parser) :
            _holder(std::shared_ptr<anyparser::holder>(
                        new anyparser::holder_sub<_Parser<T>>(std::shared_ptr<_Parser<T>>(parser))))
        {};
        
        auto parse(Lexer& lexer) -> NodePtr const;
                    
        auto match(Lexer &lexer) -> bool const;
        
        auto addElement(ElementPtr element) -> void;
    };
    

    // MARK: - Parser Elements -
    
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
    
    // MARK: - Primary Parsers -
    
    /// Primitiveな値にマッチするパーサーです。
    /// 公開は Parser.[name] 以下で行われています。
    template<class T = wf::ast::Node>
    class _PrimaryParser: public _Parser<T> {
    public:
        virtual ~_PrimaryParser() {}
        virtual auto isMatch(TokenPtr token) -> bool const = 0;
               
        auto match(Lexer& lexer) -> bool const override;
        auto parse(Lexer& lexer) -> std::shared_ptr<T> const override;
    };

    class IdentifierParser: public _PrimaryParser<wf::ast::Name> {
        auto isMatch(TokenPtr token) -> bool const override;
    };
    
    class StringParser: public _PrimaryParser<wf::ast::StringLiteral>{
        auto isMatch(TokenPtr token) -> bool const override;
    };
    class IntegerParser: public _PrimaryParser<wf::ast::IntegerLiteral>{
        auto isMatch(TokenPtr token) -> bool const override;
    };
    class DirectiveParser: public _PrimaryParser<wf::ast::Directive>{
        auto isMatch(TokenPtr token) -> bool const override;
    };
    class FloatParser: public _PrimaryParser<wf::ast::FloatLiteral>{
        auto isMatch(TokenPtr token) -> bool const override;
    };
    class OperatorParser: public _PrimaryParser<wf::ast::Operator> {
        auto isMatch(TokenPtr token) -> bool const override;
    };
    class EOLParser: public _PrimaryParser<> {
        auto isMatch(TokenPtr token) -> bool const override;
    };
    
    // MARK: - Parser -

    /// ABTをより良いAPIで使用できるようにすための、ラッパーです。
    class Parser {
    public:
        _ParserPtr parser;
        
        Parser(_ParserPtr _parser);
        
        auto parse(Lexer& lexer) -> NodePtr;
        auto match(Lexer& lexer) -> bool;
        
        auto ors(std::vector<Parser> parserws) -> Parser;
        auto repeat(Parser parserw) -> Parser;
        auto skip(std::string token) -> Parser;
        auto then(Parser parserw) -> Parser;
        auto injected(Parser subParserw) -> Parser;
        auto optional(Parser parserw) -> Parser;
        
    };

template<class T = wf::ast::Node>
    Parser rule() {
        
        return Parser(_ParserPtr(new _AnyParser(new _Parser<T>)));
    }


    // MARK: - static Primary Parsers -

    static Parser p_integer = Parser(_ParserPtr(new _AnyParser(new IntegerParser())));
    static Parser p_string = Parser(_ParserPtr(new _AnyParser(new StringParser())));
    static Parser p_operator = Parser(_ParserPtr(new _AnyParser(new OperatorParser())));
    static Parser p_derective = Parser(_ParserPtr(new _AnyParser(new DirectiveParser())));
    static Parser p_identifier = Parser(_ParserPtr(new _AnyParser(new IdentifierParser())));
    
    static Parser p_eol = Parser(_ParserPtr(new _AnyParser(new EOLParser())));
}


#endif /* Parser_h */
