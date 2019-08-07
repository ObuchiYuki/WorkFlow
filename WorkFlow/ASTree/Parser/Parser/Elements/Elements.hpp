//
//  ParserElements.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/31.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef ParserElements_h
#define ParserElements_h

#include <vector>
#include <string>
#include <exception>
#include <unordered_map>

#include "rmkit.h"
#include "Parser.hpp"
#include "Lexer.hpp"

#include "Element.hpp"

#include "OrElement.hpp"
#include "ExprElement.hpp"
#include "RepeatElement.hpp"
#include "TreeElement.hpp"

namespace wf {

    /// 指定されたTokenを読み飛ばします。
    class SkipElement: public Element{
    private:
        std::vector<std::string> skipTokens;
               
    public:
        SkipElement(std::string _skipToken);
        SkipElement(std::vector<std::string> _skipTokens);

        auto match(Lexer& lexer, int gap) const -> const bool override;
        auto parse(Lexer& lexer, std::vector<NodePtr>& res) const -> void override;
        auto rstride(Lexer& lexer, int gap) const -> const int override;
        
        auto description() const -> const std::string override;
        
    };

}

#endif /* ParserElements_h */
