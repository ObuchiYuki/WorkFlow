//
//  TreeElement.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/07.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef TreeElement_h
#define TreeElement_h

#include <vector>

#include "Element.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"

namespace wf {


/// 指定された構文木をパーサー以下に追加します。
class TreeElement: public Element {
    _ParserPtr parser;
public:
    TreeElement(_ParserPtr _parser);
    
    auto match(Lexer& lexer, int gap) const -> const bool override;
    auto parse(Lexer& lexer, std::vector<ast::NodePtr>& res) const -> void override;
    auto rstride(Lexer& lexer, int gap) const -> const int override;
    
    auto description() const -> const std::string override;
};


}

#endif /* TreeElement_h */
