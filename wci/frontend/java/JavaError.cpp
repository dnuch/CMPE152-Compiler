/**
 * <h1>JavaError</h1>
 *
 * <p>Java translation errors.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <vector>
#include <map>
#include "JavaError.h"

namespace wci { namespace frontend { namespace java {

using namespace std;

bool JavaError::INITIALIZED = false;

map<JavaErrorCode, string> JavaError::SYNTAX_ERROR_MESSAGES;

void JavaError::initialize()
{
    if (INITIALIZED) return;

    vector<JavaErrorCode> error_codes =
    {
        JavaErrorCode::CANT_BREAK_OUTSIDE_LOOP,
        JavaErrorCode::CANT_CONT_OUTSIDE_LOOP,
        JavaErrorCode::COND_COMP_OFF,
        JavaErrorCode::DEF_ONLY_ONCE_IN_SWITCH,
        JavaErrorCode::EXPECTED_LEFT_PAR,
        JavaErrorCode::EXPECTED_RIGHT_PAR,
        JavaErrorCode::EXPECTED_FORW_SLASH,
        JavaErrorCode::EXPECTED_COLON,
        JavaErrorCode::EXPECTED_SEMICOLON,
        JavaErrorCode::EXPECTED_AT,
        JavaErrorCode::EXPECTED_AT_END,
        JavaErrorCode::EXPECTED_RIGHT_BRACKET,
        JavaErrorCode::EXPECTED_LEFT_BRACE,
        JavaErrorCode::EXPECTED_RIGHT_BRACE,
        JavaErrorCode::EXPECTED_EQUALS,
        JavaErrorCode::EXPECTED_CATCH,
        JavaErrorCode::EXPECTED_CONST,
        JavaErrorCode::EXPECTED_HEX_DIGIT,
        JavaErrorCode::EXPECTED_ID,
        JavaErrorCode::EXPECTED_ID_STRING_OR_NUM,
        JavaErrorCode::EXPECTED_WHILE,
        JavaErrorCode::INVALID_CHAR,
        JavaErrorCode::LABEL_NOT_FOUND,
        JavaErrorCode::LABEL_REDEFINED,
        JavaErrorCode::RET_OUTSIDE_FUNC,
        //JavaErrorCode::SYNTAX_ERROR,
        JavaErrorCode::THROW_MUST_BE_FOLL_BY_STAT_ON_SAME_LINE,
        JavaErrorCode::UNTERMINATED_COMMENT,
        JavaErrorCode::UNTERMINATED_STRING_CONST,

        // Fatal errors.
        JavaErrorCode::IO_ERROR,
        JavaErrorCode::TOO_MANY_ERRORS
    };

    vector<string> error_messages =
    {
        "Can't have 'break' outside of loop",
        "Can't have 'continue' outside of loop",
        "Conditional compilation is turned off",
        "'default' can only appear once in a 'switch' statement",
        "Expected '('",
        "Expected ')'",
        "Expected '/'",
        "Expected ':'",
        "Expected ';'",
        "Expected '@'",
        "Expected '@end'",
        "Expected ']'",
        "Expected '{'",
        "Expected '}'",
        "Expected '='",
        "Expected 'catch'",
        "Expected constant",
        "Expected hexadecimal digit",
        "Expected identifier",
        "Expected identifier, string or number",
        "Expected 'while'",
        "Invalid character",
        "Label not found",
        "Label redefined",
        "'return' statement outside of function",
        //"Syntax error",
        "Throw must be followed by an expression on the same source line",
        "Unterminated comment",
        "Unterminated string constant",

        // Fatal errors.
        "Object I/O error",
        "Too many syntax errors"
    };

    for (int i = 0; i < error_codes.size(); i++)
    {
        SYNTAX_ERROR_MESSAGES[error_codes[i]] = error_messages[i];
    }

    INITIALIZED = true;
}

}}}  // namespace wci::frontend::java
