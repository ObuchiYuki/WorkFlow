//
//  FallThroughNode.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/11.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef FallThroughNode_h
#define FallThroughNode_h

namespace wf { namespace ast {

class FallThroughNode: public Node {
public:
    FallThroughNode(std::vector<NodePtr> _children, Location _location) : Node(_children, _location) {}

    var description() const -> std::string override{
        return children[0]->description();
    }
    
};

}}


#endif /* FallThroughNode_h */
