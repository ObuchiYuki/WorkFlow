//
//  Value.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/03.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Value_hpp
#define Value_hpp

#include <string>
#include <iostream>

#include "rmkit.h"


namespace wf {namespace ast {

class Node;
typedef std::shared_ptr<Node> NodePtr;

}}

namespace wf {namespace run {

/// evalの実行に使用される値です。
class Value {
public:
    rm::any _value;
    
    Value() : _value(nil) {}
    Value(rm::any __value): _value(__value) {};
    
    static auto voidValue() -> Value {
        static auto none = Value(nil);
        return none;
    }
    
    int integer() const {
        return _value.as<int>();
    }
    std::string string() const{
        return _value.as<std::string>();
    }
    bool boolean() const{
        return _value.as<bool>();
    }
    float floating() const{
        return _value.as<float>();
    }
    
    friend std::ostream& operator << (std::ostream &os, const Value a) {
        os << a._value;
        
        return os;
    }
};

}}

#endif /* Value_hpp */
