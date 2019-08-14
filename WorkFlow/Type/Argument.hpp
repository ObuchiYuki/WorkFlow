//
//  Argument.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/14.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Argument_h
#define Argument_h

class Argument {
public:
    const TypePtr type;
    
    Argument(TypePtr _type) : type(_type) {}
};

#endif /* Argument_h */
