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
template<class T>
class _Parser;
class Element;
class _AnyParser;
class Operators;

// ==================================== //
// MARK: - Type Linking -
typedef std::shared_ptr<_AnyParser>    _ParserPtr;
typedef std::shared_ptr<Element>       ElementPtr;
typedef std::shared_ptr<ast::Leaf>     LeafPtr;
}

#include "Element.hpp"
#include "_Parser.hpp"
#include "_AnyParser.hpp"
#include "Operators.hpp"
#include "Elements/ParserElements.hpp"
#include "PrimaryParsers.hpp"

namespace wf {
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
        auto expression(Parser subParserw, Operators ops) -> Parser;
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
