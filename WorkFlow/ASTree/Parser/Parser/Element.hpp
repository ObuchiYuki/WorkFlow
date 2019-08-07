//
//  Element.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/31.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Element_h
#define Element_h

#include "Parser.hpp"
#include "Lexer.hpp"

#include <unordered_map>
#include <vector>

namespace wf {
    /// パーサーが実際にパースする際の行動を決定します。
    /// Elementを継承して、match、parseを失踪してください。
    class Element{
    public:
        // =============================================================== //
        // MARK: - Properties -
        
        std::unordered_map<int, int> mutable rstride_memo;
        std::unordered_map<int, bool> mutable match_memo;
        
        // =============================================================== //
        // MARK: - Methods -
        
        /// 要素が現在のLexer+gapにマッチするかを返します。
        auto isMatch(Lexer& lexer, int gap) const -> bool const {
            let absIndex = lexer.absIndex(gap);
            try {
                return match_memo.at(absIndex);
                
            } catch (std::exception e) {
                let result = match(lexer, gap);
                match_memo[absIndex] = result;
                
                return result;
            }
        }
        
        /// 現在のLexer+gapに関しての相対的トークン量を返します。
        auto getRstride(Lexer& lexer, int gap) const -> int const {
            let absIndex = lexer.absIndex(gap);
            try {
                return rstride_memo.at(absIndex);
            } catch (std::exception e) {
                let result = rstride(lexer, gap);
                rstride_memo[absIndex] = result;
                
                return result;
            }
        }
        
        
        virtual auto parse(Lexer& lexer, std::vector<NodePtr>& res) const -> void = 0;
        virtual auto description() const -> const std::string = 0;
        
    private:
        
        virtual auto match(Lexer& lexer, int gap) const -> const bool = 0;
        virtual auto rstride(Lexer& lexer, int gap) const -> const int = 0;
    };
}

#endif /* Element_h */
