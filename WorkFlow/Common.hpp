//
//  Common.hpp
//  Iguanous
//
//  Created by yuki on 2019/07/12.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef _Common_hpp
#define _Common_hpp

#include <vector>
#include <string>
#include <iostream>

#define var auto
#define let const auto

template <typename T>
std::ostream & operator << (std::ostream & outstream, const std::vector<T> vector) {
    if (vector.empty()) {
        outstream << "[]";
        return outstream;
    }
    
    outstream << "[";
    outstream << vector.front();
    
    for (decltype(vector.size()) i = 1, c = vector.size(); i < c; ++i) {
        outstream << ", ";
        outstream << vector[i];
    }
    
    outstream << "]";
    
    return outstream;
}

inline void print() { std::cout << std::endl; }
        
template<class T, class... A>
inline void print(const T& first, const A&... rest) {
    std::cout << first << " "; print(rest...);
}
        
template<class... A>
inline void print(const A&... rest) {
    print(rest...);
}



#endif /* IGCommonMacros_hpp */

