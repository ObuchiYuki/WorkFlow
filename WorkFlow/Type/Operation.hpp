//
//  Operation.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/15.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Operation_hpp
#define Operation_hpp

#include "Type.hpp"

namespace wf {namespace type {

class Operation {
    
public:
    // MARK: - Enum -
    /// しばらくはinfix以外実装しないので、無視して良い
    enum class Fix {
        in, // x + x
        post, // x++
        pre // -x
    };
    
    // MARK: - Properties -
    
    const Fix fix;
    const std::string name;
    
    // (Int,Int) -> (Int)　のように
    const TypePtr left; // nullable
    const TypePtr right; // nullable
    const TypePtr returnType;
    
    // MARK: - Constructor -
    Operation(Fix _fix, std::string _name,TypePtr _left,TypePtr _right,TypePtr _returnType) :
    fix(_fix), name(_name) , left(_left), right(_right), returnType(_returnType)
    {}

    auto operator == (Operation& other) -> bool {
        return
        name == other.name   ||
        left == other.left   ||
        right == other.right ||
        returnType == other.returnType;
    }
    
};

}}

#endif /* Operation_hpp */
