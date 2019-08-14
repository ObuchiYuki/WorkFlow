//
//  SkipElement.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/07.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef SkipElement_h
#define SkipElement_h

#include <vector>
#include <string>

#include "Element.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"

namespace wf {

/// 指定されたTokenを読み飛ばします。
class SkipElement: public Element{
private:
    std::vector<std::string> skipTokens;
           
public:
    SkipElement(std::string _skipToken);
    SkipElement(std::vector<std::string> _skipTokens);

    var isEdgeParser() const -> bool override {return true;}
    auto match(Lexer& lexer, int gap) const -> const bool override;
    auto parse(Lexer& lexer, std::vector<ast::NodePtr>& res) const -> void override;
    auto rstride(Lexer& lexer, int gap) const -> const int override;
    
    auto description() const -> const std::string override;
    
};


}

#endif /* SkipElement_h */
