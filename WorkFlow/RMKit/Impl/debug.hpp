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




static inline void dprint() {
    std::cout << std::endl ;
}
        
template<class T, class... A>
static inline void dprint(const T& first, const A&... rest) {
    std::cout << first << " ";
    dprint(rest...);
}

}

namespace setting {
    
static bool use_debag = false;
static bool use_warn = false;

}


template<class... T>
void debug(const T&... rest) {
    if (rm::setting::use_debag){
        rm::__debug::dprint(rest...);
    }
}

template<class... T>
void warn(const T&... rest) {
    if (rm::setting::use_warn){
        std::cout << "⚠️ ";
        rm::__debug::dprint(rest...);
    }
}

}

#endif /* debug_h */
