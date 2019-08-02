//
//  optional.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/01.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef rm_optional_h
#define rm_optional_h

#include <iostream>
#include <new>
#include <type_traits>
#include <functional>

#define nil rm::_nil

namespace rm {

class __nil {};

static __nil _nil;

template <typename T>
class optional {
    
private:
    mutable T* data_pointer;
    typename std::aligned_storage<sizeof(T), __alignof(T)>::type data;
    
public:
    // MARK: - Connstructors -
    optional() : data_pointer(nullptr) { } // nil init
    
    optional(const T& it) :
    data_pointer(new(&data) T(it)) {}
    
    optional(const __nil& it) : // nil init
    data_pointer(nullptr) {}
    
    optional(const optional<T>& it) {
        if(data_pointer) data_pointer = new(&data) T(*it);
        else             data_pointer = nullptr;
    }
    
    template <typename ...Args>
    optional(Args ...args) :
    data_pointer(new(&data) T(args...)) {}
    
    // MARK: - Deconnstructor -
    ~optional() {
        if(data_pointer) data_pointer->~T();
    }
    
    // MARK: - Operators -
    optional<T> operator = (const T& it) {
        data_pointer = new(&data) T(it);
        return *this;
    }
    optional<T> operator = (const optional& it) {
        data_pointer = new(&data) T(*it);
        return *this;
    }
    optional<T> operator = (const __nil& it) {
        data_pointer = nullptr;
        return *this;
    }
    bool operator == (const optional& it) const {
        return data_pointer == it.data_pointer;
    }
    
    bool operator != (const optional& it) const {
        return data_pointer != it.data_pointer;
    }
    
    T& operator * () const {
        return *data_pointer;
    }
    T* operator -> () const {
        return data_pointer;
    }
    
    operator bool() const {
        return data_pointer;
    }
    
    friend std::ostream& operator << (std::ostream &os,const optional<T>& n) {
        if (n) os << "optinal(" << *n << ")";
        else   os << "nil";
        
        return os;
    }
};

}

#endif /* optinal_h */
