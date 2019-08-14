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

#include "location.hpp"

namespace wf {namespace token {
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
        /// シンボル
        SYMBOL          = 10,
        /// 演算子
        OPERATOR        = 20,
        /// 整数
        INTEGER         = 40,
        /// 文字列リテラル
        STRING          = 50,
        /// 不動小数点リテラル
        FLOAT           = 60,
        /// コンパイラディレクティブ
        DIRECTIVE       = 70,
    };
inline std::string TokenTypeDescription(TokenType tokenType){
    switch (tokenType) {
        case TokenType::ENDFILE: return "EOF";
        case TokenType::ENDLINE: return "EOL";
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::SYMBOL: return "SYMBOL";
        case TokenType::OPERATOR: return "OPERATOR";
        case TokenType::INTEGER: return "INTEGER";
        case TokenType::STRING: return "STRING";
        case TokenType::FLOAT: return "FLOAT";
        case TokenType::DIRECTIVE: return "DIRECTIVE";
        default: break;
    }
}
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
        
        auto description() const -> std::string {
            if (type == TokenType::ENDLINE) {
                return "\n";
            }else{
                return value;
            }
        }
        
        friend std::ostream& operator << (std::ostream &os, const Token token) {
            os << "[Token<" << TokenTypeDescription(token.type) << ">](" <<  token.value <<")";
            
            return os;
        }
        
    };
        
    /// END OF FILE
    
    static std::shared_ptr<wf::token::Token> EOFToken =
        std::shared_ptr<wf::token::Token>(new Token({-1, -1}, TokenType::ENDFILE, "EOF"));
        
    /// END OF LINE
    static std::shared_ptr<wf::token::Token> EOLToken =
        std::shared_ptr<wf::token::Token> (new Token({-1, -1}, TokenType::ENDLINE, "EOL"));

    typedef std::shared_ptr<Token> TokenPtr;
    
}}

#endif
