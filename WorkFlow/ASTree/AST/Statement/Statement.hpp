//
//  Statement.hpp
//  WorkFlow
//
//  Created by yuki on 2019/07/31.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Statement_h
#define Statement_h

#include "Node.hpp"


namespace wf {namespace ast {
class VarStem: public Node {
public:
    var target() -> NodePtr;
    var init() -> NodePtr;
            
    VarStem(std::vector<NodePtr> _children, Location _location);
            
    var description() -> std::string const override;
        
    auto eval(wf::run::Environment& env) -> wf::run::Value override;
};
    
class IfStem:public Node {
public:
    auto condition() -> NodePtr;
    auto block() -> NodePtr;
        
    auto elseBlock() -> NodePtr;
        
    auto description() -> std::string const override;
        
    IfStem(std::vector<NodePtr> _children, Location _location);
        
    auto eval(wf::run::Environment& env) -> wf::run::Value override;
};

class BlockStem: public Node {
public:
        
    BlockStem(std::vector<NodePtr> _children, Location _location);
        
    auto description() -> std::string const override;
        
    wf::run::Value eval(wf::run::Environment &env) override;
};
    
class WhileStem: public Node {
public:
        
    auto condition() -> NodePtr;
    auto block() -> NodePtr;
        
    WhileStem(std::vector<NodePtr> _children, Location _location);
        
    auto description() -> std::string const override;

    wf::run::Value eval(wf::run::Environment &env) override;
};

class Assgin: public Node {
public:
    auto target() -> NodePtr {
        return children[0];
    }
    auto value() -> NodePtr{
        return children[1];
    }
        
    Assgin(std::vector<NodePtr> _children, Location _location) :
    Node(_children, _location) {}
        
    auto description() -> std::string const override {
        return "(" + target()->description() + " = " + value()->description() + ")";
    }

    wf::run::Value eval(wf::run::Environment& env) override {
        let s_target = nodeAsLeaf(target())->token->value;
        var r_value = value()->eval(env);

        env.set(s_target, r_value);
        
        
        return wf::run::Value::voidValue();
    }
};

class NullStem: public Node {
public:
    NullStem(std::vector<NodePtr> _children, Location _location) :
    Node(_children, _location) {}
    
    auto description() -> std::string const override {
        return "[NullStem]";
    }
    
    wf::run::Value eval(wf::run::Environment &env) override {
        return wf::run::Value::voidValue();
    }
};


}}


#endif /* Statement_h */
