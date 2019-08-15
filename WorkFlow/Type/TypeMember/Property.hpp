//
//  Property.h
//  WorkFlow
//
//  Created by yuki on 2019/08/14.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Property_h
#define Property_h

#include <memory>
namespace wf {namespace type {

class Property {
public:
    const std::string name;
    const TypePtr type;
  
    Property(std::string _name, TypePtr _type) : name(_name), type(_type) {}
    
};

typedef std::shared_ptr<Property> PropertyPtr;

}}


#endif /* Property_h */
