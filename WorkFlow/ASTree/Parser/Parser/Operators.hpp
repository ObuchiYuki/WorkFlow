//
//  Operators.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/31.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Operators_hpp
#define Operators_hpp

#include <set>
#include <string>

namespace wf {

class Operators {
    std::set<std::string> oprs;
public:
    auto add(std::string op) -> void {
        oprs.insert(op);
    }
    auto match(std::string op) -> bool {
        return oprs.count(op) != 0;
    }
};
}

#endif /* Operators_hpp */
