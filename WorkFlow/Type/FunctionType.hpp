//
//  FunctionType.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/15.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef FunctionType_hpp
#define FunctionType_hpp

#include <vector>
#include <string>

#include "rmkit.h"
#include "Type.hpp"

namespace wf {namespace type {

class FunctionType: public Type {
public:
    const std::vector<TypePtr> arguments;
    const TypePtr returnType;
    
    FunctionType(std::vector<TypePtr> _arguments, TypePtr _returnType) :
    Type(FunctionType::functionName(_arguments, _returnType)),
    arguments(_arguments), returnType(_returnType) {}
    
    static auto functionName(std::vector<TypePtr> arguments, TypePtr returnType) -> std::string {
        return "(" + rm::description::join<TypePtr>(arguments,", ", [](let& e){return e->description();}) + ") -> " + returnType->description();
    }
    
    auto match(std::vector<TypePtr> _arguments) const -> bool {
        return arguments == _arguments;
    }
};

typedef std::shared_ptr<FunctionType> FunctionTypePtr;

}}

#endif /* FunctionType_hpp */
