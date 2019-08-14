//
//  Element.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/31.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Element_h
#define Element_h

#include "Lexer.hpp"
#include "Node.hpp"

#include <unordered_map>
#include <vector>

namespace wf {
    /// パーサーが実際にパースする際の行動を決定します。
    /// Elementを継承して、match、parseを実装してください。
    class Element{
    private:
        // MARK: - Private Properties -
        
        /// match結果のメモ
        std::unordered_map<int, bool> mutable match_memo;
        
        /// rstride結果のメモ
        std::unordered_map<int, int> mutable rstride_memo;
        
    public:
        // MARK: - Methods -
        
        
        
        /// 要素が現在のLexer+gapにマッチするかを返します。
        auto isMatch(Lexer& lexer, int gap) const -> bool const;
        
        /// 現在のLexer+gapに関しての相対的トークン量を返します。
        auto getRstride(Lexer& lexer, int gap) const -> int const;
        
        virtual var isEdgeParser() const -> bool = 0;
        
        /// lexerを元に要素をパースします。結果はresに収納されます。
        virtual auto parse(Lexer& lexer, std::vector<wf::ast::NodePtr>& res) const -> void = 0;
        
        /// Elementの詳細情報を返します。
        virtual auto description() const -> const std::string = 0;
        
    private:
        
        // MARK: - Private Methods -
        /// ElementがLexer+gapにマッチするかを返します。
        virtual auto match(Lexer& lexer, int gap) const -> const bool = 0;
        
        /// Elementがどこまでのトークンにマッチするかを返します。
        virtual auto rstride(Lexer& lexer, int gap) const -> const int = 0;
    };
}

#endif /* Element_h */
