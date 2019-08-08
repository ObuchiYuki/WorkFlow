//
//  debug.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/05.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef rm_debug_h
#define rm_debug_h

namespace rm {namespace __debug {

// ============================================== //
// MARK: - Private Mathods -
static inline void dprint() {
    std::cout << std::endl ;
}
template<class T, class... A>
static inline void dprint(const T& first, const A&... rest) {
    std::cout << first << " ";
    dprint(rest...);
}

}

// ============================================== //
// MARK: - Settings -
static bool use_debag = true;
static bool use_warn = true;

// 与えられた引数をdebug出力します。
// 引数の型に指定はありません。
template<class... T>
void debug(const T&... rest) {
    if (rm::use_debag){
        rm::__debug::dprint(rest...);
    }
}

// 与えられた引数をwarn出力します。
// 引数の型に指定はありません。
template<class... T>
void warn(const T&... rest) {
    if (rm::use_warn){
        std::cout << "⚠️ ";
        rm::__debug::dprint(rest...);
    }
}

}

#endif /* debug_h */
