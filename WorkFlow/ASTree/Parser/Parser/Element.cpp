//
//  Element.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/07.
//  Copyright © 2019 yuki. All rights reserved.
//

#include <exception>
#include <unordered_map>

#include "Lexer.hpp"

#include "Element.hpp"

using namespace wf;

/// 要素が現在のLexer+gapにマッチするかを返します。
auto Element::isMatch(Lexer& lexer, int gap) const -> bool const {
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
auto Element::getRstride(Lexer& lexer, int gap) const -> int const {
    let absIndex = lexer.absIndex(gap);
    try {
        return rstride_memo.at(absIndex);
    } catch (std::exception e) {
        let result = rstride(lexer, gap);
        rstride_memo[absIndex] = result;
        
        return result;
    }
}

