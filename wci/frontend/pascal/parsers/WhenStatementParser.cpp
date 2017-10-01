/**
 * <h1>WhenStatementParser</h1>
 *
 * <p>Parse a Pascal WHEN statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <set>
#include "WhenStatementParser.h"
#include "StatementParser.h"
#include "AssignmentStatementParser.h"
#include "ExpressionParser.h"
#include "../PascalParserTD.h"
#include "../PascalToken.h"
#include "../PascalError.h"
#include "../../Token.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

bool WhenStatementParser::INITIALIZED = false;

set<PascalTokenType> WhenStatementParser::ARROW_SET;

void WhenStatementParser::initialize()
{
    if(INITIALIZED) return;

    ARROW_SET = StatementParser::STMT_START_SET;
    ARROW_SET.insert(PascalTokenType::ARROW);

    set<PascalTokenType>::iterator it;
    for (it  = StatementParser::STMT_FOLLOW_SET.begin();
         it != StatementParser::STMT_FOLLOW_SET.end();
         it++)
    {
        ARROW_SET.insert(*it);
    }

    INITIALIZED = true;
}

WhenStatementParser::WhenStatementParser(PascalParserTD *parent)
    : StatementParser(parent)
{
    initialize();
}

ICodeNode *WhenStatementParser::parse_statement(Token *token) throw (string)
{
    token = next_token(token);  // consume the WHEN

    // Create a WHEN node.
    ICodeNode *when_node =
            ICodeFactory::create_icode_node((ICodeNodeType) NT_WHEN);

    do {
        // Parse the expression.
        // The WHEN node adopts the WHEN_BRANCH subtree as its first child.
        when_node->add_child(parse_branch(token));
        token = current_token();
        if(token->get_type() == (TokenType) PT_SEMICOLON) {
            token = next_token(token);
        } else {
            error_handler.flag(token, MISSING_SEMICOLON, this);
        }
    }  while(!(token->get_type() == (TokenType) PT_OTHERWISE) && (token != nullptr) &&
            !(token->get_type() == (TokenType) PT_END));

    // WHEN node adopts OTHERWISE node as second child.
    when_node->add_child(parse_otherwise(token));

    if(token->get_type() == (TokenType) PT_END) {
        next_token(token);  // consume the END
    } else {
        error_handler.flag(token, MISSING_END, this);
    }

    return when_node;
}

ICodeNode *WhenStatementParser::parse_branch(Token *token)
throw (string)
{
    // Create an WHEN_BRANCH node.
    ICodeNode *branch_node =
            ICodeFactory::create_icode_node(
                    (ICodeNodeType) NT_WHEN_BRANCH);

    // Parse expression
    ExpressionParser expression_parser(this);
    branch_node->add_child(expression_parser.parse_statement(token));

    // Look for the => token.
    token = synchronize(ARROW_SET);
    if (token->get_type() == (TokenType) PT_ARROW) {
        token = next_token(token);  // consume the arrow
    } else {
        error_handler.flag(token, MISSING_ARROW, this);
    }

    // Parse the WHEN branch statement. The WHEN_BRANCH node adopts
    // the statement subtree as its second child.
    StatementParser statementParser(this);
    branch_node->add_child(statementParser.parse_statement(token));

    return branch_node;
}

ICodeNode *WhenStatementParser::parse_otherwise(Token *token)
throw (string)
{
    // Create an OTHERWISE_BRANCH node.
    ICodeNode *otherwise_node =
            ICodeFactory::create_icode_node(
                    (ICodeNodeType) NT_OTHERWISE);

    // Look for the OTHERWISE token.
    if(token->get_type() == (TokenType) PT_OTHERWISE) {
        next_token(token);  // consume OTHERWISE
    } else {
        error_handler.flag(token, MISSING_OTHERWISE, this);
    }

    // Look for the => token.
    token = synchronize(ARROW_SET);
    if(token->get_type() == (TokenType) PT_ARROW) {
        token = next_token(token);  // consume the arrow
    } else {
        error_handler.flag(token, MISSING_ARROW, this);
    }

    // Parse the OTHERWISE branch statement. The OTHERWISE node adopts
    // the statement subtree as its second child.
    StatementParser statementParser(this);
    otherwise_node->add_child(statementParser.parse_statement(token));

    return otherwise_node;
}

}}}}  // namespace wci::frontend::pascal::parsers
