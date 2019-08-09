//
//  location.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/02.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef location_h
#define location_h

#include <string>

namespace wf {
    struct Location {
        int line;
        int colmun;
        
        Location(int _line, int _colmun) : line(_line), colmun(_colmun) {};
        
        auto description() const -> std::string {
            return "Line: " + std::to_string(line) + ", Colmun: " + std::to_string(colmun);
        }
    };
}

#endif /* location_h */
