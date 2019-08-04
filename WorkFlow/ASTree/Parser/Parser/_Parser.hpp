//
//  _Parser.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/31.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef _Parser_h
#define _Parser_h

namespace wf {
    /// 実際にパースを行います。
    template<class T> // T: Node
    class _Parser {
    public:
        virtual ~_Parser() {};
        std::vector<ElementPtr> elements;
                 
        /// Lexer& が Perserにマッチしているかを調べます。
        auto match(Lexer& lexer, int stride) -> bool const {
            
            
        }
                 
        /// Lexerの値を元に実際にパースを行います。
        auto parse(Lexer& lexer) -> NodePtr const {
            std::vector<NodePtr> results = {};
                       
            for (let &element: elements) {
                element->parse(lexer, results);
            }
            
            let rsize = results.size();

            if (rsize == 0) {
                return nullptr;
                
            } else if (rsize == 1 and rm::type::equals<ast::Node, T>()) {
                
                return results[0];
            } else {
                
                return std::shared_ptr<T>(new T(results, results[0]->location));
            }
        }
        
        auto rpeek(Lexer& lexer, int stride) -> int const {
            var _stride = stride;
              
            for (let &element: elements) {
                _stride += element.rpeek(lexer, _stride)

            }
            
            return _stride;
        }
          
        auto addElement(ElementPtr element) -> void{
           
            elements.push_back(element);
        }
    };
}
#endif /* _Parser_h */
