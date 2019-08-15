//
//  Calling.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/04.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Calling_h
#define Calling_h

#include "Expression.hpp"
#include "ArgumentList.hpp"
#include "PrimaryNode.hpp"

namespace wf {namespace ast{

class Calling: public Expression {
public:
    // MARK: - Properties -
    var target() const -> std::shared_ptr<Name>;
    var args() const -> std::shared_ptr<ArgumentList>;
    var returnType() const -> type::TypePtr override;
    
    // MARK: - Constructor -
    Calling(std::vector<NodePtr> _children, Location _location);
    
    // MARK: - Methods -
    auto description() const -> std::string override;

};


}}
#endif /* Calling_h */
