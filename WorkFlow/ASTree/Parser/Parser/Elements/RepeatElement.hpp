//
//  RepeatElement.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/07.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef RepeatElement_h
#define RepeatElement_h

#include <vector>

#include "Element.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"


namespace wf {

/// 登録されたパーサーに複数回マッチするかを調べます。
class RepeatElement: public Element{
private:
    _ParserPtr parser;
    
    bool isOptional;
public:
    RepeatElement(_ParserPtr _parser, bool _once);
    
    auto match(Lexer& lexer, int gap) const -> const bool override;
    auto parse(Lexer& lexer, std::vector<NodePtr>& res) const -> void override;
    auto rstride(Lexer& lexer, int gap) const -> const int override;
    
    auto description() const -> const std::string  override;
};


}


#endif /* RepeatElement_h */
