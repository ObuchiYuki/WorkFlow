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

#include <vector>

namespace wf {
    /// パーサーが実際にパースする際の行動を決定します。
    /// Elementを継承して、match、parseを失踪してください。
    class Element{
    public:
               
        virtual auto match(Lexer& lexer, int stride) -> bool const = 0;
        virtual auto parse(Lexer& lexer, std::vector<NodePtr>& res) -> void const = 0;
        virtual auto rstride(Lexer& lexer, int gap) -> int const = 0;
    };
}

#endif /* Element_h */
