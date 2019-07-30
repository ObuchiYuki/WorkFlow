//
//  Lexer.hpp
//  Iguanous
//
//  Created by yuki on 2019/07/13.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Lexer_hpp
#define Lexer_hpp

#include <string>
#include <vector>
#include <fstream>
#include <memory>

#include "../Token.hpp"
#include "../../Common.hpp"

typedef std::shared_ptr<wf::token::Token> TokenPtr;

namespace wf {
    class Lexer {
        // MARK: - Private -
    private:
        // MARK: - Properties -
        /// Fileの読み取り&用のReaderです。
        int lineNumber;
        
        std::ifstream* reader;
        
        /// 現在の行のToken列です。
        std::vector<TokenPtr> queue;
        
        /// 現在の行が最終行かどうかです。
        bool hasMoreLine;
        
        // MARK: - Methods -
        
        /// 先の行を読み込みます。読み込みができたらtrueできなかったらfalseを返します。　
        const bool loadNext(int stride);
        
        /// 現在の行を解釈します。
        const void readLine();
        
        // MARK: - Public -
    public:
        // ======================================================= //
        // MARK: - Constructor -
        
        Lexer(std::ifstream* _reader) :
        reader(_reader), lineNumber(1) , hasMoreLine(true), queue({}) {}
        
        // ======================================================= //
        // MARK: - Methods -
        
        /// 次のQueueを読みます。読んだところからメモリから消します。
        TokenPtr readNext();
        
        /// 先のQueueを先読みします。メモリから消すことはありません。
        TokenPtr peek(int stride);
        
    };
}

#endif /* Lexer_hpp */
