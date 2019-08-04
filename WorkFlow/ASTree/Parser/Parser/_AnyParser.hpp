//
//  _AnyParser.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/31.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef _AnyParser_h
#define _AnyParser_h

#include <memory>

#include "Parser.hpp"
#include "Lexer.hpp"

// MARK: - AnyParsr
namespace wf {
class _AnyParser {

private:
    class holder {
    public:
        
        virtual auto parse(Lexer& lexer) -> NodePtr const = 0;
        virtual auto match(Lexer& lexer, int gap) -> bool const = 0;
        virtual auto rstride(Lexer& lexer, int gap) -> int const = 0;
        virtual auto addElement(ElementPtr element) -> void = 0;
        
        
    };
    
    template<typename T> // T: Parser<S>
    struct holder_sub : public holder {
    
        std::shared_ptr<T> parser;
        holder_sub(std::shared_ptr<T> _parser) : parser(_parser) {};
        
        auto parse(Lexer& lexer) -> NodePtr const override {
            
            return parser->parse(lexer);
        }
        
        auto match(Lexer& lexer, int gap) -> bool const override {
            
            return parser->match(lexer, gap);
        }
        
        auto rstride(Lexer& lexer, int gap) -> int const override {
            return parser->rstride(lexer, gap);
        }
        
        auto addElement(ElementPtr element) -> void override {
            
            parser->addElement(element);
        }
    };
    
    std::shared_ptr<holder> _holder;
    
    public:
    
    template<typename T>
    _AnyParser(_Parser<T>* parser) :
        _holder(std::shared_ptr<holder>( new holder_sub<_Parser<T>>( std::shared_ptr<_Parser<T>>(parser)) ))
        {};
        
    auto parse(Lexer& lexer) -> NodePtr const;
                
    auto match(Lexer &lexer, int gap) -> bool const;
        
    auto addElement(ElementPtr element) -> void;
    
    auto rstride(Lexer& lexer, int gap) -> int const;
    };
}



#endif /* _AnyParser_h */
