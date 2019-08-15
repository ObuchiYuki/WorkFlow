//
//  Operation.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/15.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Operation_hpp
#define Operation_hpp

#include <memory>
#include "Type.hpp"


namespace wf {namespace type {

// (Infix)
class Operation: public Method {
    
public:
    
    // MARK: - Properties -
    
    var left() const -> TypePtr {
        return arguments[0].type;
    }
    var right() const -> TypePtr{
        return arguments[1].type;
    }

    auto operator == (Operation& other) -> bool {
        return
        name == other.name       &&
        left() == other.left()   &&
        right() == other.right();
    }
};
    
typedef std::shared_ptr<Operation> OperationPtr;
    

}}

#endif /* Operation_hpp */
