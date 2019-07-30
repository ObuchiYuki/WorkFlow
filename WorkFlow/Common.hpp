//
//  IGCommonMacros.hpp
//  Iguanous
//
//  Created by yuki on 2019/07/12.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef IGCommonMacros_hpp
#define IGCommonMacros_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

#define fatalError(message) print(message); exit(1)
#define var auto
#define let const auto

#define nil(type) (optinal<type>())
#define guard_let(name, expression) var _name = expression ; if (!_name.has_value())return; let name = _name.value()
#define guard_let_else(name, expression, elv) var _name = expression ; if (!_name.has_value())return elv; let name = _name.value()
#define cast_let(name, value, clazz) var __name = dynamic_cast<clazz>(value);clazz name; if (__name == nullptr){ name = optinal<clazz>();}else{name = optinal<clazz>(__name);}

template<class T>
struct optinal{

    // MARK: - Constructor -
    optinal(T __value): _has_value(true), _value(__value) {}
    optinal(): _has_value(false), _value() {};
    // MARK: - Methods -
    T value(){
        if (_has_value){
            return _value;
        }else{
            throw "FatalError: nil fonud when unwrapping optinal value.";
        }
    }
    bool has_value() const{
        return _has_value;
    }
    // MARK: - Operator -
        
    T* operator ->(){
        if (_has_value) {
            return &_value;
        } else {
            return nullptr;
        }
    }
    
    // MARK: - Properties -
private:
    T _value;
    bool _has_value;
};

template<class T>
static std::ostream & operator << (std::ostream & outstream, const optinal<T>opt) {
        if (opt.has_value()){
            outstream << opt.values();
        }else{
            outstream << "nil";
        }
        
    return outstream;
}
    

namespace wf {
    struct Location {
        int line;
        int colmun;
        
        Location(int _line, int _colmun) : line(_line), colmun(_colmun) {};
    };
}

template <typename T>
std::ostream & operator << (std::ostream & outstream, const std::vector<T> vector) {
    if (vector.empty()) {
        outstream << "[]";
        return outstream;
    }
    
    outstream << "[";
    outstream << vector.front();
    
    for (decltype(vector.size()) i = 1, c = vector.size(); i < c; ++i) {
        outstream << ", ";
        outstream << vector[i];
    }
    
    outstream << "]";
    
    return outstream;
}

#endif /* IGCommonMacros_hpp */
