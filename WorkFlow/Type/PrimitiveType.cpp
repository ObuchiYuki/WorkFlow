//
//  PrimitiveType.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/15.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "PrimitiveType.hpp"
#include "FunctionType.hpp"
#include "Function.hpp"

using namespace wf::type;

TypePtr PrimitiveType::Void =        TypePtr(new Type("Void"));
TypePtr PrimitiveType::Int =          TypePtr(new Type("Int"));
TypePtr PrimitiveType::Bool =         TypePtr(new Type("Bool"));
TypePtr PrimitiveType::String =       TypePtr(new Type("String"));
TypePtr PrimitiveType::Array =        TypePtr(new Type("Array"));
TypePtr PrimitiveType::Dictionary =   TypePtr(new Type("Dictionary"));
TypePtr PrimitiveType::Float =        TypePtr(new Type("Float"));

auto PrimitiveType::registerAll() -> void {
    Type::global->registerType(Int);
    Type::global->registerType(Bool);
    Type::global->registerType(String);
    Type::global->registerType(Array);
    Type::global->registerType(Dictionary);
    Type::global->registerType(Float);
    
    Type::global->registerProperty(std::make_shared<Function>(Function("+", {Int, Int}, Int)));
    Type::global->registerProperty(std::make_shared<Function>(Function("-", {Int, Int}, Int)));
    Type::global->registerProperty(std::make_shared<Function>(Function("*", {Int, Int}, Int)));
    Type::global->registerProperty(std::make_shared<Function>(Function("/", {Int, Int}, Int)));
    Type::global->registerProperty(std::make_shared<Function>(Function("==", {Int, Int}, Bool)));
    
    Type::global->registerProperty(std::make_shared<Function>(Function("+", {String, String}, String)));
    Type::global->registerProperty(std::make_shared<Function>(Function("*", {String, Int}, String)));
    
    Type::global->registerProperty(std::make_shared<Function>(Function("print", {String}, Void)));
}
