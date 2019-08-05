//
//  debug.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/05.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef rm_debug_h
#define rm_debug_h

namespace rm {namespace debug {

static constexpr bool use_debug = false;

}

inline constexpr void dprint() {
    if (rm::debug::use_debug) {
        std::cout << std::endl ;
    }
}
        
template<class T, class... A>
inline constexpr void dprint(const T& first, const A&... rest) {
    if (rm::debug::use_debug) {
        std::cout << first << " ";
        dprint(rest...);
    }
}
        
template<class... A>
inline constexpr void dprint(const A&... rest) {
    if (rm::debug::use_debug) {
        dprint(rest...);
    }
}


}

#endif /* debug_h */
