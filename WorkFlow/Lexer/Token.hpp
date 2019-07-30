//
//  Token.hpp
//  Iguanous
//
//  Created by yuki on 2019/07/13.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Token_hpp
#define Token_hpp

#include <string>
#include <iostream>
#include <memory>


#include "../Common.hpp"

namespace wf {
    
    namespace token {
        // =============================================================== //
        // MARK: - TokenType -
        // トークンのタイプです。
        enum class TokenType: unsigned short {
            /// ファイルの終端です。
            ENDFILE         = 201,
            /// 行の終端です。
            ENDLINE         = 202,
            /// 名前
            IDENTIFIER      = 0,
            /// 整数
            INTEGER         = 40,
            /// 文字列リテラル
            STRING          = 50,
            /// 不動小数点リテラル
            FLOAT           = 60,
            /// コンパイラディレクティブ
            DIRECTIVE       = 70,
        };
        // =============================================================== //
        // MARK: - Token -
            
        /// Lexerによって処理される、字句解析結果です。
        class Token {
            
        public:
            // ================================= //
            // - Constructor -
            Token(const wf::Location _location, const TokenType _type, const std::string _value) :
            location(_location), type(_type), value(_value) {} ;
            
            // ================================= //
            // - Properties -
            
            /// トークンの場所です。
            const wf::Location location;
            
            /// トークンのタイプです。
            const wf::token::TokenType type;
            
            /// トークンの中身です。
            const std::string value;
            
            const bool isEnd() const {
                return type == TokenType::ENDFILE || type == TokenType::ENDLINE;
            }
            
        };
            
        /// END OF FILE
        
        static std::shared_ptr<wf::token::Token> EOFToken =
            std::shared_ptr<wf::token::Token>(new Token({-1, -1}, TokenType::ENDFILE, "EOF"));
            
        /// END OF LINE
        static std::shared_ptr<wf::token::Token> EOLToken =
            std::shared_ptr<wf::token::Token> (new Token({-1, -1}, TokenType::ENDLINE, "EOL"));
    }
}

    
// =============================================================== //
// - Stream Extensions -
static std::ostream & operator << (std::ostream & outstream, const wf::token::TokenType type) {
    switch (type) {
            /// ファイルの終端です。
        case wf::token::TokenType::ENDFILE: outstream << "ENDFILE"; break;
        case wf::token::TokenType::ENDLINE: outstream << "ENDLINE"; break;
        case wf::token::TokenType::IDENTIFIER: outstream << "IDENTIFIER"; break;
        case wf::token::TokenType::INTEGER: outstream << "INTEGER"; break;
        case wf::token::TokenType::STRING: outstream << "STRING"; break;
        case wf::token::TokenType::FLOAT: outstream << "FLOAT"; break;
        case wf::token::TokenType::DIRECTIVE: outstream << "DIRECTIVE"; break;
            
        default: break;
    }
    
    return outstream;
}
static std::ostream & operator << (std::ostream & outstream, const wf::token::Token* token) {
    outstream << "<wf::Token ,type: ";
    outstream << token->type;
    outstream << ", value: \"" << token->value;
    
    outstream << "\">";
    
    return outstream;
}
    
#endif /* Token_hpp */
