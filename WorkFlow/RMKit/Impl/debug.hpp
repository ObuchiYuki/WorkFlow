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

static bool use_debug = true;


static inline void _dprint() {
    std::cout << std::endl ;
}
        
template<class T, class... A>
static inline void _dprint(const T& first, const A&... rest) {
    std::cout << first << " ";
    _dprint(rest...);
}

}

template<class... T>
void dprint(const T&... rest) {
    if (rm::debug::use_debug){
        rm::debug::_dprint(rest...);
    }
}


}

#endif /* debug_h */
