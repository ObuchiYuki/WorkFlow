//
//  Parser.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/25.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Parser_h
#define Parser_h

#include "Elements/ExprElement.hpp"
#include "_AnyParser.hpp"
#include "_Parser.hpp"
#include "FallThroughNode.hpp"

namespace wf {
// MARK: - Parser -

/// ABTをより良いAPIで使用できるようにするためのラッパーです。
class Parser {
private:
    auto _integer() -> Parser;
    auto _string() -> Parser;
    auto _name() -> Parser;
    auto _op() -> Parser;
    auto _directive() -> Parser;
public:
    _ParserPtr parser;
    
    Parser(): parser(nullptr) {};
    Parser(_ParserPtr _parser);
    
    auto parse(Lexer& lexer) -> wf::ast::NodePtr;
    auto match(Lexer& lexer) -> bool;
        
    auto ors(std::vector<Parser> parserws) -> Parser;
    auto repeat(Parser parserw) -> Parser;
    auto skip(std::string token) -> Parser;
    auto skip(std::vector<std::string> tokens) -> Parser;
    auto then(Parser parserw) -> Parser;
    auto expression(Parser subParserw, Operators& ops) -> Parser;
    auto optional(Parser parserw) -> Parser;
    auto optionalRepeat(Parser parserw) -> Parser;
    auto insertChoise(Parser parserw) -> Parser;
    auto skipEol() -> Parser;
            
    static auto integer() -> Parser;
    static auto string() -> Parser;
    static auto name() -> Parser;
    static auto op() -> Parser;
    static auto directive() -> Parser;
    
    auto description() const -> const std::string;
    
    static auto addReservedWord(std::string word) -> void;
};

template<class T = wf::ast::Node>
inline Parser rule() {
    return Parser(_ParserPtr(new _AnyParser(new _Parser<T>)));
}

inline Parser ruleWithNoOmit() {
    return Parser(_ParserPtr(new _AnyParser(new _Parser<wf::ast::FallThroughNode>())));
}

}


#endif /* Parser_h */
