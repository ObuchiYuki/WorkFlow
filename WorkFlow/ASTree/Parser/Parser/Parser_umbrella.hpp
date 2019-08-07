//
//  Parser_umbrella.hpp
//  WorkFlow
//
//  Created by yuki on 2019/08/07.
//  Copyright © 2019 yuki. All rights reserved.
//

#ifndef Parser_umbrella_h
#define Parser_umbrella_h

#include <string>
#include <memory>
#include <vector>

#include "Node.hpp"
#include "Lexer.hpp"
#include "AST.hpp"

/// 循環的な定義の為先頭定義が必要
namespace wf {
// ====================================================================== //
// MARK: - Type Definitions -
template<class T>
class _Parser;
class Element;
class _AnyParser;

// ==================================== //
// MARK: - Type Linking -
typedef std::shared_ptr<_AnyParser>    _ParserPtr;
typedef std::shared_ptr<Element>       ElementPtr;

}

#include "Element.hpp"
#include "Elements/Elements.hpp"
#include "Elements/TokenElements.hpp"

#include "_Parser.hpp"
#include "_AnyParser.hpp"
#include "Parser.hpp"


#endif /* Parser_umbrella_h */
