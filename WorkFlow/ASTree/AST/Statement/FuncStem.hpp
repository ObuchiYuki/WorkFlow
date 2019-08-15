//
//  FuncStem.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/08.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef FuncStem_hpp
#define FuncStem_hpp

#include "Node.hpp"
#include "ParameterList.hpp"
#include "Statement.hpp"
#include "PrimaryNode.hpp"

namespace wf {namespace ast{

class FuncStem: public Node {
public:
    var name() const -> std::shared_ptr<wf::ast::Name>;
    var parameters() const -> std::shared_ptr<wf::ast::ParameterList>;
    var body() const -> std::shared_ptr<wf::ast::BlockStem>;
    
    FuncStem(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {};
        
    var description() const -> std::string override {
        return "(def " + name()->description() + parameters()->description() + body()->description() + ")";
    }
    
};

}}

#endif /* FuncStem_hpp */
