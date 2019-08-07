//
//  OrElement.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/07.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef OrElement_h
#define OrElement_h

#include "Element.hpp"

/// 登録されたパーサーの中からマッチするものを探します。
/// 結果を保持されます。

namespace wf {

class OrElement: public Element{
private:
    // MARK: - Private Properties -
    
    /// 分岐するパーサーです。このどれかにマッチするかを調べます。
    std::vector<_ParserPtr> parsers;
    
    /// 分岐にマッチしたパーサーが入ります。
    /// memo[absIndex: MatchedParser]
    std::unordered_map<int, _ParserPtr> mutable matched_parser_memo;
    
public:
               
    // MARK: - Constructor -
    OrElement(std::vector<_ParserPtr> _parsers) : parsers(_parsers) {}
    
    // MARK: - Overrided Methods -
    auto match(Lexer& lexer, int gap) const -> bool const override;
    auto parse(Lexer& lexer, std::vector<NodePtr>& res) const -> void override;
    auto rstride(Lexer& lexer, int gap) const -> int const override;
    
    auto description() const -> const std::string override;
    
private:
    
    // MARK: - Private Methods -
    
    /// 現在のLexer + gap にマッチするパーサーを探します。
    /// 結果は保持されます。
    auto chooseParser(Lexer& lexer, int gap) const -> const _ParserPtr;

};

}


#endif /* OrElement_h */
