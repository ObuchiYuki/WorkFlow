//
//  BlockStem.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/09.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef BlockStem_h
#define BlockStem_h

#include <string>
#include <vector>

#include "Location.hpp"
#include "Node.hpp"

namespace wf {namespace ast {
    

class BlockStem: public Node {
public:
        
    BlockStem(std::vector<NodePtr> _children, Location _location);
        
    var description() const -> std::string override;
        
};


}}


#endif /* BlockStem_h */
