//
//  Type.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/14.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Type_hpp
#define Type_hpp

#include <string>
#include <memory>

#include "rmkit.h"

namespace wf {namespace ast {

class Type;

typedef std::shared_ptr<Type> TypePtr;

/// 型を表します。
class Type {
public:
    // MARK: - Properties -
    /// 型名
    const std::string name;
    const TypePtr parent;
    
    // MARK: - Methods -
    
    auto isChildrenOf(Type type) const -> bool;
    
    // MARK: - Constructor -
    Type(std::string _name) : name(_name) , parent(nullptr) {}
    Type(std::string _name, TypePtr _parent) : name(_name) , parent(_parent) {}
    
    // MARK: - Operator -
    bool operator == (const Type& it) const {
        return name == it.name;
    }
    
    // MARK: - Static Properties -
    
    static TypePtr Int;
    static TypePtr String;
    static TypePtr Array;
    static TypePtr Dictionary;
    static TypePtr Float;
};



}}

#endif /* Type_hpp */
