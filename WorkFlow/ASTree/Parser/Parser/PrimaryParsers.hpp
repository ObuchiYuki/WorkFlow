//
//  PrimaryParsers.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/31.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef PrimaryParsers_h
#define PrimaryParsers_h

#include <memory>
#include "Parser.hpp"

namespace wf {
// MARK: - Primary Parsers -
    /// Primitiveな値にマッチするパーサーです。
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
    
}
#endif /* PrimaryParsers_h */
