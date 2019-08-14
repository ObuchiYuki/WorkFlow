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

namespace wf {namespace type {

class Type;

typedef std::shared_ptr<Type> TypePtr;

#include "Property.hpp"
#include "Argument.hpp"
#include "Method.hpp"

/// 型を表します。
class Type {
public:
    // MARK: - Properties -
    const std::string name;
    const TypePtr parent;
    
    // MARK: - Type Restriction -
    std::vector<Property> properties;
    std::vector<Method> methods;
    
    std::vector<Property> staticProperties;
    std::vector<Method> staticMethods;
    
    // MARK: - Methods -
    
    auto isChildrenOf(Type type) const -> bool;
    auto description() -> std::string {return name;}
    
    // MARK: - Constructor -
    Type(std::string _name) : name(_name) , parent(nullptr) {}
    Type(std::string _name, TypePtr _parent) : name(_name) , parent(_parent) {}
    
    // MARK: - Operator -
    bool operator == (const Type& it) const {
        return name == it.name;
    }
};



}}

#endif /* Type_hpp */
