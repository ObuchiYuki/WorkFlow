//
//  Method.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/14.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Method_h
#define Method_h

#include <memory>

namespace wf {namespace type {

class Method {
public:
    const std::string name;
    const TypePtr returnType;
    const std::vector<Argument> arguments;
    
    virtual ~Method() {}
    
    Method(std::string _name, TypePtr _returnType, std::vector<Argument> _arguments) :
        name(_name), returnType(_returnType), arguments(_arguments)
        {}
    
};

typedef std::shared_ptr<Method> MethodPtr;

}}


#endif /* Methods_h */
