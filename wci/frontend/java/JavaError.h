/**
 * <h1>JavaError</h1>
 *
 * <p>Java translation errors.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_JAVA_JAVAERROR_H_
#define WCI_FRONTEND_JAVA_JAVAERROR_H_

#include <string>
#include <map>

namespace wci { namespace frontend { namespace java {

using namespace std;

/**
 * Java error codes.
 */
enum class JavaErrorCode
{
    CANT_BREAK_OUTSIDE_LOOP,
    CANT_CONT_OUTSIDE_LOOP,
    COND_COMP_OFF,
    DEF_ONLY_ONCE_IN_SWITCH,
    EXPECTED_LEFT_PAR,
    EXPECTED_RIGHT_PAR,
    EXPECTED_FORW_SLASH,
    EXPECTED_COLON,
    EXPECTED_SEMICOLON,
    EXPECTED_AT,
    EXPECTED_AT_END,
    EXPECTED_RIGHT_BRACKET,
    EXPECTED_LEFT_BRACE,
    EXPECTED_RIGHT_BRACE,
    EXPECTED_EQUALS,
    EXPECTED_CATCH,
    EXPECTED_CONST,
    EXPECTED_HEX_DIGIT,
    EXPECTED_ID,
    EXPECTED_ID_STRING_OR_NUM,
    EXPECTED_WHILE,
    INVALID_CHAR,
    INVALID_NUMBER,
    LABEL_NOT_FOUND,
    LABEL_REDEFINED,
    RANGE_INTEGER,
    RANGE_REAL,
    RET_OUTSIDE_FUNC,
    THROW_MUST_BE_FOLL_BY_STAT_ON_SAME_LINE,
    UNEXPECTED_EOF,
    UNTERMINATED_COMMENT,
    UNTERMINATED_STRING_CONST,

    // Fatal errors.
    IO_ERROR,
    TOO_MANY_ERRORS
};

constexpr JavaErrorCode CANT_BREAK_OUTSIDE_LOOP = JavaErrorCode::CANT_BREAK_OUTSIDE_LOOP;
constexpr JavaErrorCode CANT_CONT_OUTSIDE_LOOP = JavaErrorCode::CANT_CONT_OUTSIDE_LOOP;
constexpr JavaErrorCode COND_COMP_OFF = JavaErrorCode::COND_COMP_OFF;
constexpr JavaErrorCode DEF_ONLY_ONCE_IN_SWITCH = JavaErrorCode::DEF_ONLY_ONCE_IN_SWITCH;
constexpr JavaErrorCode EXPECTED_LEFT_PAR = JavaErrorCode::EXPECTED_LEFT_PAR;
constexpr JavaErrorCode EXPECTED_RIGHT_PAR = JavaErrorCode::EXPECTED_RIGHT_PAR;
constexpr JavaErrorCode EXPECTED_FORW_SLASH = JavaErrorCode::EXPECTED_FORW_SLASH;
constexpr JavaErrorCode EXPECTED_COLON = JavaErrorCode::EXPECTED_COLON;
constexpr JavaErrorCode EXPECTED_SEMICOLON = JavaErrorCode::EXPECTED_SEMICOLON;
constexpr JavaErrorCode EXPECTED_AT = JavaErrorCode::EXPECTED_AT;
constexpr JavaErrorCode EXPECTED_AT_END = JavaErrorCode::EXPECTED_AT_END;
constexpr JavaErrorCode EXPECTED_RIGHT_BRACKET = JavaErrorCode::EXPECTED_RIGHT_BRACKET;
constexpr JavaErrorCode EXPECTED_LEFT_BRACE = JavaErrorCode::EXPECTED_LEFT_BRACE;
constexpr JavaErrorCode EXPECTED_RIGHT_BRACE = JavaErrorCode::EXPECTED_RIGHT_BRACE;
constexpr JavaErrorCode EXPECTED_EQUALS = JavaErrorCode::EXPECTED_EQUALS;
constexpr JavaErrorCode EXPECTED_CATCH = JavaErrorCode::EXPECTED_CATCH;
constexpr JavaErrorCode EXPECTED_CONST = JavaErrorCode::EXPECTED_CONST;
constexpr JavaErrorCode EXPECTED_HEX_DIGIT = JavaErrorCode::EXPECTED_HEX_DIGIT;
constexpr JavaErrorCode EXPECTED_ID = JavaErrorCode::EXPECTED_ID;
constexpr JavaErrorCode EXPECTED_ID_STRING_OR_NUM = JavaErrorCode::EXPECTED_ID_STRING_OR_NUM;
constexpr JavaErrorCode EXPECTED_WHILE = JavaErrorCode::EXPECTED_WHILE;
constexpr JavaErrorCode INVALID_CHAR = JavaErrorCode::INVALID_CHAR;
constexpr JavaErrorCode INVALID_NUMBER = JavaErrorCode::INVALID_NUMBER;
constexpr JavaErrorCode LABEL_NOT_FOUND = JavaErrorCode::LABEL_NOT_FOUND;
constexpr JavaErrorCode LABEL_REDEFINED = JavaErrorCode::LABEL_REDEFINED;
constexpr JavaErrorCode RANGE_INTEGER = JavaErrorCode::RANGE_INTEGER;
constexpr JavaErrorCode RANGE_REAL = JavaErrorCode::RANGE_REAL;
constexpr JavaErrorCode RET_OUTSIDE_FUNC = JavaErrorCode::RET_OUTSIDE_FUNC;
constexpr JavaErrorCode THROW_MUST_BE_FOLL_BY_STAT_ON_SAME_LINE = JavaErrorCode::THROW_MUST_BE_FOLL_BY_STAT_ON_SAME_LINE;
constexpr JavaErrorCode UNEXPECTED_EOF = JavaErrorCode::UNEXPECTED_EOF;
constexpr JavaErrorCode UNTERMINATED_COMMENT = JavaErrorCode::UNTERMINATED_COMMENT;
constexpr JavaErrorCode UNTERMINATED_STRING_CONST = JavaErrorCode::UNTERMINATED_STRING_CONST;


constexpr JavaErrorCode IO_ERROR = JavaErrorCode::IO_ERROR;
constexpr JavaErrorCode TOO_MANY_ERRORS = JavaErrorCode::TOO_MANY_ERRORS;

class JavaError
{
public:
    static map<JavaErrorCode, string> SYNTAX_ERROR_MESSAGES;

    /**
     * Initialize the static map.
     */
    static void initialize();

private:
    static bool INITIALIZED;
};

}}}  // namespace wci::frontend::java

#endif /* WCI_FRONTEND_JAVA_JAVAERROR_H_ */
