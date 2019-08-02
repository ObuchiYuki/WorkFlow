//
//  Common.hpp
//  Iguanous
//
//  Created by yuki on 2019/07/12.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef _Common_hpp
#define _Common_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

#include "rmkit.h"

#define var auto
#define let const auto

namespace wf {
    struct Location {
        int line;
        int colmun;
        
        Location(int _line, int _colmun) : line(_line), colmun(_colmun) {};
    };
}

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

template<class T>
void print(const T item) {
    std::cout << item << std::endl;
}


#endif /* IGCommonMacros_hpp */

