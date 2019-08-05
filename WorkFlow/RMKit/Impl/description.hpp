//
//  description.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/05.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef description_h
#define description_h

#include <string>
#include <vector>

namespace rm {namespace description {
    
template<typename T>
std::string vector(std::vector<T> vector, std::function<T(std::string)> tranceform){
    std::string decra = "";
    if (vector.empty()) {
        decra += "[]";
        return decra;
    }
    
    decra += "[";
    decra += tranceform(vector.front());
    
    for (decltype(vector.size()) i = 1, c = vector.size(); i < c; ++i) {
        decra += ", ";
        decra += tranceform(vector[i]);
    }
    
    decra += "]";
    
    return decra;
}

}}

#endif /* description_h */
