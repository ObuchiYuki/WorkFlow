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


namespace wf {
    class Lexer {
        // MARK: - Private -
    private:
        // MARK: - Properties -
        
        int lineNumber;
        
        /// Fileの読み取り&用のReaderです。
        std::ifstream* reader;
        
        /// 現在の行のToken列です。
        std::vector<token::TokenPtr> queue;
        
        /// 現在の行が最終行かどうかです。
        bool hasMoreLine;
        
        // MARK: - Methods -
        
        /// 先の行を読み込みます。読み込みができたらtrueできなかったらfalseを返します。　
        const bool loadNext(int stride);
        
        /// 現在の行を解釈します。
        const void readLine();
        
        // MARK: - Public -
        
        /// 現在読み終わったトークンの場所です。
        int index = 0;
        
    public:
        
        
        int absIndex(int gap) {
            return index + gap;
        }

        // ======================================================= //
        // MARK: - Constructor -
        
        Lexer(std::ifstream* _reader) :
        reader(_reader), lineNumber(1) , hasMoreLine(true), queue({}) {}
        
        // ======================================================= //
        // MARK: - Methods -
        
        /// 次のQueueを読みます。読んだところからメモリから消します。
        token::TokenPtr readNext();
        
        /// 先のQueueを先読みします。メモリから消すことはありません。
        token::TokenPtr peek(int stride);
        
        
        auto description(int gap) -> const std::string{
            return "'" +
            peek(gap)->description() + " " +
            peek(gap+1)->description() + " " +
            peek(gap+2)->description() + " " +
            peek(gap+3)->description() + " " +
            peek(gap+4)->description() + " " +
            peek(gap+5)->description() + "...'";
            
        }
        
        /// 先頭のTokenのIndexです。
        int currentIndex();
        
    };
}

#endif /* Lexer_hpp */
