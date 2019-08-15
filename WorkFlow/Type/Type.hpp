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
    
    // MARK: - Methods -
    
    auto registerType(TypePtr type) -> void;
    auto registerProperty(PropertyPtr prop) -> void;
    
    auto isChildrenOf(Type type) const -> bool;
    virtual var description() -> std::string {return name;}
    
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

#include "FunctionType.hpp"
#include "PrimitiveType.hpp"


#endif /* Type_hpp */
