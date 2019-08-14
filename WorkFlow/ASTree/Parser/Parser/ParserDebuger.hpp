//
//  ParserDebuger.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/14.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef ParserDebuger_hpp
#define ParserDebuger_hpp

namespace wf {

class ParserDebuger {
    static int _maxMatch;
    
public:
    static auto getMaxMatch() -> int {
        return _maxMatch;
    }
    static auto registerMaxMatch(int absIndex){
        if (_maxMatch < absIndex) {
            _maxMatch = absIndex;
        }
    }
};

}

#endif /* ParserDebuger_hpp */
