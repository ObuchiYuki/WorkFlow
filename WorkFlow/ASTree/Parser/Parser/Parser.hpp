//
//  Parser.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/25.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Parser_h
#define Parser_h

#include <string>
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
typedef std::shared_ptr<ast::Node>     NodePtr;

}

#include "_Parser.hpp"
#include "_AnyParser.hpp"

#include "Element.hpp"
#include "Elements/Elements.hpp"
#include "Elements/TokenElements.hpp"

namespace wf {
    // MARK: - Parser -

    /// ABTをより良いAPIで使用できるようにすための、ラッパーです。
class Parser {
private:
    auto _integer() -> Parser;
    auto _string() -> Parser;
    auto _name() -> Parser;
    auto _op() -> Parser;
public:
    _ParserPtr parser;
    
    Parser(): parser(nullptr) {};
    Parser(_ParserPtr _parser);
    
    auto parse(Lexer& lexer) -> NodePtr;
    auto match(Lexer& lexer) -> bool;
        
    auto ors(std::vector<Parser> parserws) -> Parser;
    auto repeat(Parser parserw) -> Parser;
    auto skip(std::string token) -> Parser;
    auto skip(std::vector<std::string> tokens) -> Parser;
    auto then(Parser parserw) -> Parser;
    auto expression(Parser subParserw, Operators ops) -> Parser;
    auto optional(Parser parserw) -> Parser;
            
    static auto integer() -> Parser;
    static auto string() -> Parser;
    static auto name() -> Parser;
    static auto op() -> Parser;
};

template<class T = wf::ast::Node>
Parser rule() {
    return Parser(_ParserPtr(new _AnyParser(new _Parser<T>)));
}

}


#endif /* Parser_h */
