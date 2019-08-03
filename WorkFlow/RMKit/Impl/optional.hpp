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
#include <type_traits>

/// nilを簡易的に使用できるようにするためのマクロです。
#define nil rm::_nil::shared()

namespace rm {

/// 何もない値を表します。
/// シングルトンである`nil`から使用してください。
class _nil {
private:
    _nil(){}
public:
    /// nilのシングルトンです。
    static _nil& shared(){
        static _nil instance;
        return instance;
    }
};


template <typename T>
/**
 存在するか存在しないかのどちらかの状態を表します。
 存在する場合は、`optional<T>(value)` 存在しない場合は、`nil`を使用して初期化します。
 
 -- 使用 --
 ```
 /// 失敗するかもしれない関数 (String -> Int)
 rm::optional<int> toInt(string value) {...}
 
 cout << toInt("10") << endl;   // optional(10)
 cout << *toInt("10") << endl;  // 10
 
 auto str = toInt("hello");
 auto num = toInt("1000");
 
 if (str) { // 呼ばれない
    cout << *str << endl;
 }
 
 if (num) { // 呼ばれる
    cout << *num << endl; // 1000
 }
 
 optional<vector<int>> nil_list = nil;
 
 nil_list->push_back(1) // Error
 
 optional<vector<int>> val_list = {12, 13};
 
 val_list->push_back(14) // {12, 13, 14}
 
 ```
*/
class optional {
private:
    // ======================================================================== //
    /// 実態を表します。
    mutable T* data_pointer;
    typename std::aligned_storage<sizeof(T), __alignof(T)>::type data;
    
public:
    // ======================================================================== //
    // MARK: - Connstructors -
    
    /// ポインタ`optional`の初期化です。nullptrだった場合は、nilになります。
    optional(const T* it) :
    data_pointer(it) {}
    
    /// 存在するものからの`optional`の初期化です。
    optional(const T& it) :
    data_pointer(new(&data) T(it)) {}
    
    /// 複数の引数を取る存在するものからの`optional`の初期化です。
    template <typename ...Args>
    optional(Args ...args) :
    data_pointer(new(&data) T(args...)) {}
    
    /// `nil`からの`optional`の初期化です。
    optional(const _nil& it) :
    data_pointer(nullptr) {}
    
    /// コピーコンストラクタ
    optional(const optional<T>& it) {
        if(data_pointer) data_pointer = new(&data) T(*it);
        else             data_pointer = nullptr;
    }
    
    // ======================================================================== //
    // MARK: - Deconnstructor -
    ~optional() {
        if (data_pointer) data_pointer->~T();
    }
    
    // ======================================================================== //
    // MARK: - Operators -
    /// 実態を代入します。
    optional<T> operator = (const T& it) {
        data_pointer = new(&data) T(it);
        return *this;
    }
    
    /// `optional`を代入します。
    optional<T> operator = (const optional& it) {
        data_pointer = new(&data) T(*it);
        return *this;
    }
    
    /// `nil`を代入します。
    optional<T> operator = (const _nil& it) {
        data_pointer = nullptr;
        return *this;
    }
    
    /// 比較演算子です。内部の値を比較します。
    bool operator == (const optional& it) const {
        return data_pointer == it.data_pointer;
    }
    
    /// 比較演算子です。内部の値を比較します。
    bool operator != (const optional& it) const {
        return data_pointer != it.data_pointer;
    }
    
    /// 実態を取り出します。nilに対して実行すると未定義動作です。
    /// まず、チェックしてから実行してください。
    T& operator * () const {
        return *data_pointer;
    }
    
    /// 実態を取り出します。nilに対して実行すると未定義動作です。
    /// まず、チェックしてから実行してください。
    T* operator -> () const {
        return data_pointer;
    }
    
    /// 実態が`nil`なのかを判別する`bool`を返します。
    /// `nil`の時、`false`, `some`の時`true`となります。
    operator bool() const {
        return data_pointer;
    }
    
    ///　optionalを出力します。
    friend std::ostream& operator << (std::ostream &os,const optional<T>& n) {
        if (n) os << "optinal(" << *n << ")";
        else   os << "nil";
        
        return os;
    }
};

}

#endif /* optinal_h */
