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

}}

#include "Property.hpp"
#include "Argument.hpp"
#include "Method.hpp"
#include "Operation.hpp"

namespace wf {namespace type {

/// 型を表します。
class Type {
public:
    // MARK: - Properties -
    const std::string name;
    const TypePtr parent;
    
    // MARK: - Type Restriction -
    std::vector<TypePtr> types;
    std::vector<PropertyPtr> properties;
    std::vector<MethodPtr> methods;
    
    std::vector<PropertyPtr> staticProperties;
    std::vector<MethodPtr> staticMethods;
    
    // MARK: - Methods -
    
    auto registerType(TypePtr type) -> void;
    auto registerProperty(PropertyPtr prop) -> void;
    auto registerMethod(MethodPtr method) -> void;
    
    auto searchOperation(std::string name, TypePtr left, TypePtr right) -> OperationPtr;
    
    auto isChildrenOf(Type type) const -> bool;
    auto description() -> std::string {return name;}
    
    // MARK: - Constructor -
    Type(std::string _name) : name(_name) , parent(nullptr) {}
    Type(std::string _name, TypePtr _parent) : name(_name) , parent(_parent) {}
    
    // MARK: - Operator -
    bool operator == (const Type& it) const {
        return name == it.name;
    }
    
    static TypePtr global;
};



}}

#endif /* Type_hpp */
