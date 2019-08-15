//
//  TypeManager.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/15.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef TypeManager_hpp
#define TypeManager_hpp

#include <vector>

#include "rmkit.h"
#include "Type.hpp"

namespace wf {namespace type {
    
class TypeManager {

public:
    static TypeManager shared;
    
    auto registerType(TypePtr type) -> void {
        _registeredType.push_back(type);
    }
    
    auto typeExsists(TypePtr type) const -> bool {
        return _registeredType.contains(type);
    }
private:
    static rm::vector<TypePtr> _registeredType;
};

}}

#endif /* TypeManager_hpp */
