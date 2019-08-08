//
//  vector.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/08.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef rm_vector_h
#define rm_vector_h

#include <vector>
#include <functional>

namespace rm {

template<typename T>
class vector: public std::vector<T> {
public:
    // MARK: - Methods -
    auto contains(const T& element) -> const bool {
        auto itr = std::find(this->begin(), this->end(), element);
        
        return itr != this->end();
        
    }
    template<typename U>
    auto map(std::function<T(U)> tranceform) -> rm::vector<U> {
        rm::vector<U> result;
        
        for (const auto &elm: *this) {
            result.push_back(tranceform(elm));
        }
        
        return result;
    }
    
    // MARK: - Constructor - 
    vector(){}
};

}




#endif /* vector_h */
