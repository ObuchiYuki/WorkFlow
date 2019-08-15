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
#include "Function.hpp"

namespace wf {namespace ast{

class FuncStem: public Node {
public:
    var name() const -> std::shared_ptr<wf::ast::Name>;
    var parameters() const -> std::shared_ptr<wf::ast::ParameterList>;
    var body() const -> std::shared_ptr<wf::ast::BlockStem>;
    
    FuncStem(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {};
        
    /// 今だけ
    auto eval(wf::run::EnvironmentPtr env) -> wf::run::Value override {
        let func = wf::run::Function(name(), parameters(), body());
        env->set(func.identifier, wf::run::Value(func));
        
        return wf::run::Value::voidValue();
    }
    
    var description() const -> std::string override {
        return "(def " + name()->description() + parameters()->description() + body()->description() + ")";
    }
    
};

}}

#endif /* FuncStem_hpp */
