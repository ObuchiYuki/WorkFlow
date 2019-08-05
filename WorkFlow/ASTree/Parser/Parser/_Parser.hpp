//
//  _Parser.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/31.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef _Parser_h
#define _Parser_h

#include "rmkit.h"

namespace wf {
    /// 実際にパースを行います。
    template<class T> // T: Node
    class _Parser {
    public:
        virtual ~_Parser() {};
        std::vector<ElementPtr> elements;
                 
        /// Lexer& が Perserにマッチしているかを調べます。
        auto match(Lexer& lexer, int gap) -> bool const {
            var rstride = 0;
            var rgap = gap;
            
            for (let &element: elements) {
                if (!element->match(lexer, rgap)) return false;
                let a = element->rstride(lexer, rgap);
                    
                rstride += a;
                rgap += a;
            }
            
            return true;
            
        }
                 
        /// Lexerの値を元に実際にパースを行います。
        auto parse(Lexer& lexer) -> NodePtr const {
            std::vector<NodePtr> results = {};
                       
            for (let &element: elements) {
                element->parse(lexer, results);
            }
            
            let rsize = results.size();

            if (rsize == 0) {
                rm::dprint("[_Parser::parse] Nothing matched. Something wrong...? This node will be omitted.");
                return std::shared_ptr<T>(new T({}, lexer.peek(0)->location));
                
            } else if (rsize == 1 and rm::type::equals<ast::Node, T>()) {
                
                return results[0];
            } else {
                
                return std::shared_ptr<T>(new T(results, results[0]->location));
            }
        }
        
        auto rstride(Lexer& lexer, int gap) -> int const {
            auto rgap = gap;
            auto rstride = 0;
            
            for (const auto &element: elements) {
                auto a = element->rstride(lexer, rgap);
              
                rgap += a;
                rstride += a;
            }

            return rstride;
        }
          
        auto addElement(ElementPtr element) -> void{
           
            elements.push_back(element);
        }
        
        auto description() -> std::string const {
            auto dec = std::vector<std::string>();
            
            for (let &e:elements) {
                dec.push_back(e->description());
            }
            
            
            return "_Parser<" + rm::type::type_name<T>() + ">(elements = " +
           rm::description::vector(dec)
            + ")";
        }
    };
}
#endif /* _Parser_h */
