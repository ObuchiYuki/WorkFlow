//
//  PrimitiveType.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/15.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "PrimitiveType.hpp"

using namespace wf::type;

TypePtr PrimitiveType::Int =          TypePtr(new Type("Int"));
TypePtr PrimitiveType::Bool =          TypePtr(new Type("Bool"));
TypePtr PrimitiveType::String =       TypePtr(new Type("String"));
TypePtr PrimitiveType::Array =        TypePtr(new Type("Array"));
TypePtr PrimitiveType::Dictionary =   TypePtr(new Type("Dictionary"));
TypePtr PrimitiveType::Float =        TypePtr(new Type("Float"));
