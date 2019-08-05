//
//  debug.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/05.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef rm_debug_h
#define rm_debug_h

namespace rm {

inline void dprint() {
    //std::cout << std::endl;
}
        
template<class T, class... A>
inline void dprint(const T& first, const A&... rest) {
    //std::cout << first << " "; dprint(rest...);
}
        
template<class... A>
inline void dprint(const A&... rest) {
    //dprint(rest...);
}


}

#endif /* debug_h */
