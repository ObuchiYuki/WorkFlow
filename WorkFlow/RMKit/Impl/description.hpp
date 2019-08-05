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
    
inline std::string vector(std::vector<std::string> vector){
    std::string decra = "";
    if (vector.empty()) {
        decra += "[]";
        return decra;
    }
    
    decra += "[";
    decra += vector.front();
    
    for (decltype(vector.size()) i = 1, c = vector.size(); i < c; ++i) {
        decra += ", ";
        decra += vector[i];
    }
    
    decra += "]";
    
    return decra;
}

}}

#endif /* description_h */
