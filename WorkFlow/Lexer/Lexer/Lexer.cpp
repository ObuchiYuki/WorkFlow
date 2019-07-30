//
//  Lexer.cpp
//  Iguanous
//
//  Created by yuki on 2019/07/13.
//  Copyright © 2019 yuki. All rights reserved.
//

// ==================================================== //
// MARK: - Imports -
#include <vector>
#include <regex>
#include <string>
#include <memory>
#include <fstream>

#include "../Token.hpp"
#include "../../Common.hpp"

#include "Lexer.hpp"

using namespace wf::token;
typedef std::shared_ptr<Token> TokenPtr;

/// IGHelpers
namespace wfh {
    // =============================================================== //
    // MARK: - Classes -
    
    /// 字句解析時の環境をカプセル化します。
    class _ReadingEnvironment{
    public:
        /// 現在読んでいる行です。
        const std::string line;
        
        /// 現在読んでいる行の行数です。
        const int lineno;
        
        /// 今読んでいる行の場所です。読み込みに応じて変化します。
        int columun;
        
        _ReadingEnvironment(const std::string _line, const int _lineno) :
        line(_line), lineno(_lineno), columun(0) {}
    };
    
    // =============================================================== //
    // MARK: - autotions -
    
    // ======================================== //
    // MARK: - Checking autos -
    /// 引数が数字かどうか
    bool isNumber(const unsigned char c) {
        return ('0' <= c && c <= '9');
    }
    
    /// 引数がNameの最初の文字になれるか
    bool isNameFirstElement(const unsigned char c) {
        return
        ('a' <= c && c <= 'z') ||
        ('A' <= c && c <= 'Z') ||
        c == '_';
    }
    
    /// 引数はDirectiveの最初の文字か
    bool isDirectiveFirstElement(const unsigned char c) {
        return c == '@';
    }
    
    /// 引数がNameの最初以外の文字になれるか
    bool isNameElement(const unsigned char c) {
        return
        isNameFirstElement(c) ||
        isNumber(c);
    }
    
    bool isBracketType(const unsigned char c) {
        return strchr("()[]{}", c);
    }
    
    bool isParentheses(const unsigned char c) {
        return strchr("()", c);
    }
    
    bool isBraces(const unsigned char c) {
        return strchr("{}", c);
    }
    
    bool isBracket(const unsigned char c) {
        return strchr("[]", c);
    }
    /// 引数がSymbolどうか
    bool isSymbol(const unsigned char c) {
        return strchr(";,", c);
    }
    
    bool isOperatorFirstElement(const unsigned char c) {
        return strchr("|<>+=-*&%!~?/.", c);
    }
    
    bool isMultiCharSymbol(std::string op){
        for (let &ops: {"|>", "+=", "-=", "==", "!=", "->"}) {
            if (op == ops) return true;
        }
        return false;
    }
    
    // ======================================== //
    // MARK: - Reading autos -
    
    /// 引数に渡された環境をもとに、StringLiteralをのTokenを構成し返します。
    TokenPtr readStringLiteral(_ReadingEnvironment& env){
        var buffer = new std::string();
        let firstColumun = env.columun;
        
        env.columun += 1;
        while (env.line[env.columun] != '\"') {
            (*buffer) += env.line[env.columun];
            env.columun += 1;
        }
        let token = TokenPtr(new wf::token::Token({env.lineno, firstColumun}, TokenType::STRING, *buffer));
        
        return token;
    }
    
    /// 引数に渡された環境をもとに、IntergerLiteralをのTokenを構成し返します。
    TokenPtr readIntergerLiteral(_ReadingEnvironment& env) {
        var buffer = new std::string();
        let firstColumun = env.columun;
        
        while (isNumber(env.line[env.columun])) {
            (*buffer) += env.line[env.columun];
            env.columun += 1;
        }
        env.columun -= 1;
        let token = TokenPtr(new wf::token::Token({env.lineno, firstColumun},TokenType::INTEGER, *buffer));
        
        return token;
    }
    
    /// 引数に渡された環境をもとに、NameのTokenを構成し返します。
    TokenPtr readName(_ReadingEnvironment& env) {
        var buffer = new std::string();
        let firstColumun = env.columun;
        
        while (isNameElement(env.line[env.columun])) {
            (*buffer) += env.line[env.columun];
            env.columun += 1;
        }
        env.columun -= 1;
        let token = TokenPtr(new wf::token::Token({env.lineno, firstColumun},TokenType::IDENTIFIER, *buffer));
        
        return token;
    }
    
    TokenPtr readDirective(_ReadingEnvironment& env) {
        var buffer = new std::string();
        let firstColumun = env.columun;
        
        env.columun += 1;
        while (isNameElement(env.line[env.columun])) {
            (*buffer) += env.line[env.columun];
            env.columun += 1;
        }
        env.columun -= 1;
        let token = TokenPtr(new wf::token::Token({env.lineno, firstColumun}, TokenType::DIRECTIVE, *buffer));
        
        return token;
    }
    
    TokenPtr readBracketType(_ReadingEnvironment& env) {
        let c = env.line[env.columun];
        
        return TokenPtr(new wf::token::Token({env.lineno, env.columun}, TokenType::IDENTIFIER, std::string(1, c)));
    }
    TokenPtr readSymbol(_ReadingEnvironment& env) {
        let s = std::string(env.line[env.columun], 1);
        
        let token = TokenPtr(new wf::token::Token({env.lineno, env.columun},TokenType::IDENTIFIER, s));
        
        return token;
    }
    TokenPtr readOperator(_ReadingEnvironment& env) {
        let ops = (std::string() + env.line[env.columun]) + env.line[env.columun+1];
        
        if (isMultiCharSymbol(ops)){
            env.columun += 1;
            let token = TokenPtr(new wf::token::Token({env.lineno, env.columun},TokenType::IDENTIFIER, ops));
            
            return token;
        }
        
        let op = new std::string(1, env.line[env.columun]);
        
        let token = TokenPtr(new wf::token::Token({env.lineno, env.columun},TokenType::IDENTIFIER, *op));
        
        return token;
    }
}
// ===================================================================================== //
// MARK: - Implementions -


const bool wf::Lexer::loadNext(int stride) {
    while (stride >= queue.size()) { // strideの分が存在しないならば
        if (hasMoreLine) {// 次の行があるならば、
            lineNumber += 1;
            readLine();
        }else{
            return false;
        }
    }
    
    return true;
};

TokenPtr wf::Lexer::readNext() {
    if (loadNext(0)){
        let removingQ = queue[0];
        queue.erase(queue.begin(), queue.begin()+1);
        
        return removingQ;
    } else {
        printf("EOF");
        return wf::token::EOFToken;
    }
}

TokenPtr wf::Lexer::peek(int stride) {
    if (loadNext(stride)){
        return queue[stride];
        
    } else {
        
        return wf::token::EOFToken;
    }
}

const void wf::Lexer::readLine() {
    var lineBuffer = new std::string();
    
    if (!getline(*reader, *lineBuffer)) {
        hasMoreLine = false;
        return;
    }
    
    let endPos = lineBuffer->size();
    var env = wfh::_ReadingEnvironment(*lineBuffer, lineNumber);
    
    while (env.columun < endPos) {
        let c = (*lineBuffer)[env.columun];
        
        if (c == '\"') {
            queue.push_back(wfh::readStringLiteral(env));
            
        }else if (wfh::isNumber(c)) {
            queue.push_back(wfh::readIntergerLiteral(env));
            
        }else if (wfh::isNameFirstElement(c)){
            queue.push_back(wfh::readName(env));
            
        }else if (wfh::isBracketType(c)) {
            queue.push_back(wfh::readBracketType(env));
            
        }else if (wfh::isSymbol(c)) {
            queue.push_back(wfh::readSymbol(env));
            
        }else if (wfh::isOperatorFirstElement(c)) {
            queue.push_back(wfh::readOperator(env));
            
        }else if (wfh::isDirectiveFirstElement(c)){

            queue.push_back(wfh::readDirective(env));
        }
        
        env.columun += 1;
    }
    
    queue.push_back(wf::token::EOLToken);
}

