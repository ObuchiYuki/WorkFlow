//
//  debug.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/05.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef rm_debug_h
#define rm_debug_h

#include <chrono>

namespace rm {namespace debug {


static inline void out() {
    std::cout << std::endl ;
}

template<class T, class... A>
static inline void out(const T& first, const A&... rest) {
    std::cout << first << " ";
    out(rest...);
}

// 与えられた引数をwarn出力します。
// 引数の型に指定はありません。
template<class... T>
void warn(const T&... rest) {
    std::cout << "⚠️ ";
    rm::debug::out(rest...);
}

static std::chrono::time_point<std::__1::chrono::steady_clock, std::chrono::duration<long long, std::ratio<1, 1000000000>>> __startTime;

static inline auto startMeasure() {
    __startTime = std::chrono::high_resolution_clock::now();
}

static inline auto endMeasure(std::string message = "") {
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - __startTime).count();

    out("⏰", duration / double(1000 * 1000), "s", message);
}

}}

#endif /* debug_h */
