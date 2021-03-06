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
#include <functional>

/// 表示用のStringへの変換を行います。
namespace rm {namespace description {
    
/// テンプレートで渡されたVectorを変換して出力します。
template <typename T, typename Func>
inline std::string join(const std::vector<T>& vector, const std::string sep = ", ", Func tranceform = [](std::string s){return s;}){
    if (vector.empty()) return "";
    
    std::string decra = tranceform(vector.front());
    for (decltype(vector.size()) i = 1, c = vector.size(); i < c; ++i) decra += sep + tranceform(vector[i]);
    return decra;
}

/// テンプレートで渡されたVectorを変換して出力します。
template <typename T, typename Func>
inline std::string vector(const std::vector<T>& vector, Func tranceform){
    std::string decra = "[]";
    if (vector.empty()) return decra;
    
    decra = "[" + tranceform(vector.front());
    
    for (decltype(vector.size()) i = 1, c = vector.size(); i < c; ++i) {
        decra += ", " + tranceform(vector[i]);
    }
    
    decra += "]";
    return decra;
}

/// Vectorを出力します。
inline std::string vector(const std::vector<std::string>& vector){
    std::string decra = "[]";
    if (vector.empty()) return decra;
    
    decra = "[" + vector.front();
    
    for (decltype(vector.size()) i = 1, c = vector.size(); i < c; ++i) {
        decra += ", " + vector[i];
    }
    
    decra += "]";
    return decra;
}


}}

#endif /* description_h */
