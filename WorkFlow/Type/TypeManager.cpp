//
//  TypeManager.cpp
//  WorkFlow
//
//  Created by yuki on 2019/08/15.
//  Copyright © 2019 yuki. All rights reserved.
//

#include "TypeManager.hpp"

using namespace wf::type;

TypeManager TypeManager::shared = TypeManager();

rm::vector<TypePtr> TypeManager::_registeredType = {};
