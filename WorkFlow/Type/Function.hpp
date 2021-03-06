//
//  Function.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/15.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Function_h
#define Function_h

#include "Property.hpp"
#include "FunctionType.hpp"

namespace wf {namespace type{

class Function: public Property {
public:
    Function(std::string name, std::vector<TypePtr> _arguments, TypePtr _returnType):
        Property(name, TypePtr(new FunctionType(_arguments, _returnType))) {}
    
    static auto function_name(std::string name, std::vector<TypePtr> _arguments) -> std::string {
        
        return name + ":" + rm::description::join(_arguments, ",", [](auto e){return e->name;});
    }
};

typedef std::shared_ptr<Function> FunctionPtr;

}}


#endif /* Function_h */
