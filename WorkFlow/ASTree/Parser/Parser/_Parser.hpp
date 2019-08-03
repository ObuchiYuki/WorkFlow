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
    template<class T> // T: Access
    class _Parser {
    public:
        virtual ~_Parser() {};
        std::vector<ElementPtr> elements;
                 
        /// Lexer& が Perserにマッチしているかを調べます。
        virtual auto match(Lexer& lexer) -> bool const {
           
            return elements[0]->match(lexer);
        }
                 
        /// Lexerの値を元に実際にパースを行います。
        virtual auto parse(Lexer& lexer) -> std::shared_ptr<T> const {
            std::vector<NodePtr> results = {};
                       
            for (let &element: elements) {
                element->parse(lexer, results);
            }
            
            let rsize = results.size();
            print(rsize);
            print(rm::type::type_name<T>());
            
            if (rsize == 0) {
                return std::shared_ptr<T>(new T({}, lexer.peek(0)->location));
            } else
            if (rsize == 1) {
                for (let &a:results.front()->children) {
                    print(rm::type::type_name(*a));
                }
                
                let node = std::shared_ptr<T>(new T(results.front()->children, results[0]->location));
                
                return node;
            } else {
                let node = std::shared_ptr<T>(new T(results, results[0]->location));
                
                return node;
            }
        }
          
        auto addElement(ElementPtr element) -> void{
           
            elements.push_back(element);
        }
    };
}
#endif /* _Parser_h */
