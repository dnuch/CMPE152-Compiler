/**
 * <h1>WhenExecutor</h1>
 *
 * <p>Execute an WHEN statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <vector>
#include "WhenExecutor.h"
#include "StatementExecutor.h"
#include "ExpressionExecutor.h"
#include "../../../DataValue.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace backend { namespace interpreter { namespace executors {

using namespace std;
using namespace wci;
using namespace wci::backend::interpreter;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

WhenExecutor::WhenExecutor(Executor *parent)
    : StatementExecutor(parent)
{
}

DataValue *WhenExecutor::execute(ICodeNode *node)
{
    // Get the WHEN node's children.
    vector<ICodeNode *> children = node->get_children();
    vector<ICodeNode *> when_branch_node;
    // Last node is OTHERWISE NODE
    ICodeNode *otherwise_node = children[children.size()-1];

    ICodeNode *expr_node = nullptr;
    ICodeNode *stmt_node = nullptr;

    ExpressionExecutor expression_executor(this);
    StatementExecutor statement_executor(this);

    // Iterate until last node and execute WHEN BRANCH
    for(unsigned int i = 0; i < children.size()-1; i++) {
        when_branch_node.push_back(children[i]);
        expr_node = when_branch_node[i]->get_children()[0];
        stmt_node = when_branch_node[i]->get_children()[1];
        expression_executor.execute(expr_node);
        statement_executor.execute(stmt_node);
    }

    // Execute OTHERWISE node
    stmt_node = otherwise_node->get_children()[0];
    statement_executor.execute(stmt_node);

    ++execution_count;  // count the WHEN statement itself
    return nullptr;
}

}}}}  // namespace wci::backend::interpreter::executors