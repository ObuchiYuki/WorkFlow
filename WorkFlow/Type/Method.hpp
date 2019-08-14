//
//  Method.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/14.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Method_h
#define Method_h


class Method {
public:
    const std::string name;
    const TypePtr returnType;
    const std::vector<Argument> argument;
    
    Method(std::string _name, TypePtr _returnType, std::vector<Argument> _argument) :
        name(_name), returnType(_returnType), argument(_argument)
        {}
    
};


#endif /* Methods_h */
