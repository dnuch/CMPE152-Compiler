/**
 * <h1>JavaToken</h1>
 *
 * <p>Base class for Java token classes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */

#ifndef WCI_FRONTEND_JAVA_JAVATOKEN_H_
#define WCI_FRONTEND_JAVA_JAVATOKEN_H_

#include <string>
#include <map>
#include "../Token.h"
#include "../Source.h"

namespace wci { namespace frontend { namespace java {

using namespace std;
using namespace wci::frontend;

/**
 * Java token types.
 */
enum class JavaTokenType
{
    // Reserved words.
    ABSTRACT, DOUBLE, LONG_INT, BREAK, ELSE, SWITCH, CASE, 
    ENUM, NATIVE, SUPER, CHARACTER, EXTENDS, RETURN, THIS, CLASS, 
    FLOAT, SHORT, THROW, CONST, FOR, PACKAGE, VOID, CONTINUE, GOTO, 
    PROTECTED, VOLATILE, DO, IF, STATIC, WHILE,

    // Special symbols.
    TILDE, NOT, AT, MODULUS, BIT_XOR, BIT_AND, MULT, MINUS, PLUS, EQUAL, 
    BIT_OR, DIVIDE, COLON, SEMICOLON, QUESTIONMARK, LESS_THAN, 
    GREATER_THAN, DOT, COMMA, SINGLE_QUOTE, DOUBLE_QUOTE, TAB, NEW_LINE, LEFT_PAREN, RIGHT_PAREN,
    LEFT_BRACKET, RIGHT_BRACKET, LEFT_BRACE, RIGHT_BRACE, INCREMENT, DECREMENT,
    SHIFT_LEFT, SHIFT_RIGHT, LESS_EQUALS, GREATER_EQUALS, PLUS_ASSIGN, MINUS_ASSIGN,
    MULT_ASSIGN, DIVIDE_ASSIGN, COMPARE, BIT_OR_ASSIGN, MODULUS_ASSIGN, BIT_XOR_ASSIGN,
    NOT_EQUALS, SHIFT_LEFT_ASSIGN, SHIFT_RIGHT_ASSIGN, OR, AND, COMMENT, COMMENT_START, COMMENT_END,

    IDENTIFIER, INTEGER, REAL, STRING,
    ERROR, END_OF_FILE
};
//reserved words
constexpr JavaTokenType PT_ABSTRACT = JavaTokenType::ABSTRACT;
constexpr JavaTokenType PT_DOUBLE = JavaTokenType::DOUBLE;
constexpr JavaTokenType PT_LONG_INT = JavaTokenType::LONG_INT;
constexpr JavaTokenType PT_BREAK = JavaTokenType::BREAK;
constexpr JavaTokenType PT_ELSE = JavaTokenType::ELSE;
constexpr JavaTokenType PT_SWITCH = JavaTokenType::SWITCH;
constexpr JavaTokenType PT_CASE = JavaTokenType::CASE;
constexpr JavaTokenType PT_ENUM = JavaTokenType::ENUM;
constexpr JavaTokenType PT_NATIVE = JavaTokenType::NATIVE;
constexpr JavaTokenType PT_SUPER = JavaTokenType::SUPER;
constexpr JavaTokenType PT_CHARACTER = JavaTokenType::CHARACTER;
constexpr JavaTokenType PT_EXTENDS = JavaTokenType::EXTENDS;
constexpr JavaTokenType PT_RETURN = JavaTokenType::RETURN;
constexpr JavaTokenType PT_THIS = JavaTokenType::THIS;
constexpr JavaTokenType PT_CLASS = JavaTokenType::CLASS;
constexpr JavaTokenType PT_FLOAT = JavaTokenType::FLOAT;
constexpr JavaTokenType PT_SHORT = JavaTokenType::SHORT;
constexpr JavaTokenType PT_THROW = JavaTokenType::THROW;
constexpr JavaTokenType PT_CONST = JavaTokenType::CONST;
constexpr JavaTokenType PT_FOR = JavaTokenType::FOR;
constexpr JavaTokenType PT_PACKAGE = JavaTokenType::PACKAGE;
constexpr JavaTokenType PT_VOID = JavaTokenType::VOID;
constexpr JavaTokenType PT_CONTINUE = JavaTokenType::CONTINUE;
constexpr JavaTokenType PT_GOTO = JavaTokenType::GOTO;
constexpr JavaTokenType PT_PROTECTED = JavaTokenType::PROTECTED;
constexpr JavaTokenType PT_VOLATILE = JavaTokenType::VOLATILE;
constexpr JavaTokenType PT_DO = JavaTokenType::DO;
constexpr JavaTokenType PT_IF = JavaTokenType::IF;
constexpr JavaTokenType PT_STATIC = JavaTokenType::STATIC;
constexpr JavaTokenType PT_WHILE = JavaTokenType::WHILE; //end of reserve words
//special symbols
constexpr JavaTokenType PT_TILDE = JavaTokenType::TILDE;
constexpr JavaTokenType PT_NOT = JavaTokenType::NOT;
constexpr JavaTokenType PT_AT = JavaTokenType::AT;
constexpr JavaTokenType PT_MODULUS = JavaTokenType::MODULUS;
constexpr JavaTokenType PT_BIT_XOR = JavaTokenType::BIT_XOR;
constexpr JavaTokenType PT_BIT_AND = JavaTokenType::BIT_AND;
constexpr JavaTokenType PT_MULT = JavaTokenType::MULT;
constexpr JavaTokenType PT_MINUS = JavaTokenType::MINUS;
constexpr JavaTokenType PT_PLUS = JavaTokenType::PLUS;
constexpr JavaTokenType PT_EQUAL = JavaTokenType::EQUAL;
constexpr JavaTokenType PT_BIT_OR = JavaTokenType::BIT_OR;
constexpr JavaTokenType PT_DIVIDE = JavaTokenType::DIVIDE;
constexpr JavaTokenType PT_COLON = JavaTokenType::COLON;
constexpr JavaTokenType PT_SEMICOLON = JavaTokenType::SEMICOLON;
constexpr JavaTokenType PT_QUESTIONMARK = JavaTokenType::QUESTIONMARK;
constexpr JavaTokenType PT_LESS_THAN = JavaTokenType::LESS_THAN;
constexpr JavaTokenType PT_GREATER_THAN = JavaTokenType::GREATER_THAN;
constexpr JavaTokenType PT_DOT = JavaTokenType::DOT;
constexpr JavaTokenType PT_COMMA = JavaTokenType::COMMA;
constexpr JavaTokenType PT_SINGLE_QUOTE = JavaTokenType::SINGLE_QUOTE;
constexpr JavaTokenType PT_DOUBLE_QUOTE = JavaTokenType::DOUBLE_QUOTE;
constexpr JavaTokenType PT_TAB = JavaTokenType::TAB;
constexpr JavaTokenType PT_NEW_LINE = JavaTokenType::NEW_LINE;
constexpr JavaTokenType PT_LEFT_PAREN = JavaTokenType::LEFT_PAREN;
constexpr JavaTokenType PT_RIGHT_PAREN = JavaTokenType::RIGHT_PAREN;
constexpr JavaTokenType PT_LEFT_BRACKET = JavaTokenType::LEFT_BRACKET;
constexpr JavaTokenType PT_RIGHT_BRACKET = JavaTokenType::RIGHT_BRACKET;
constexpr JavaTokenType PT_LEFT_BRACE = JavaTokenType::LEFT_BRACE;
constexpr JavaTokenType PT_RIGHT_BRACE = JavaTokenType::RIGHT_BRACE;
constexpr JavaTokenType PT_INCREMENT = JavaTokenType::INCREMENT;
constexpr JavaTokenType PT_DECREMENT = JavaTokenType::DECREMENT;
constexpr JavaTokenType PT_SHIFT_LEFT = JavaTokenType::SHIFT_LEFT;
constexpr JavaTokenType PT_SHIFT_RIGHT = JavaTokenType::SHIFT_RIGHT;
constexpr JavaTokenType PT_LESS_EQUALS = JavaTokenType::LESS_EQUALS;
constexpr JavaTokenType PT_GREATER_EQUALS = JavaTokenType::GREATER_EQUALS;
constexpr JavaTokenType PT_PLUS_ASSIGN = JavaTokenType::PLUS_ASSIGN;
constexpr JavaTokenType PT_MINUS_ASSIGN = JavaTokenType::MINUS_ASSIGN;
constexpr JavaTokenType PT_MULT_ASSIGN = JavaTokenType::MULT_ASSIGN;
constexpr JavaTokenType PT_DIVIDE_ASSIGN = JavaTokenType::DIVIDE_ASSIGN;
constexpr JavaTokenType PT_PLUS_COMPARE = JavaTokenType::COMPARE;
constexpr JavaTokenType PT_BIT_OR_ASSIGN = JavaTokenType::BIT_OR_ASSIGN;
constexpr JavaTokenType PT_MODULUS_ASSIGN = JavaTokenType::MODULUS_ASSIGN;
constexpr JavaTokenType PT_BIT_XOR_ASSIGN = JavaTokenType::BIT_XOR_ASSIGN;
constexpr JavaTokenType PT_NOT_EQUALS = JavaTokenType::NOT_EQUALS;
constexpr JavaTokenType PT_SHIFT_LEFT_ASSIGN = JavaTokenType::SHIFT_LEFT_ASSIGN;
constexpr JavaTokenType PT_SHIFT_RIGHT_ASSIGN = JavaTokenType::SHIFT_RIGHT_ASSIGN;
constexpr JavaTokenType PT_OR = JavaTokenType::OR;
constexpr JavaTokenType PT_AND = JavaTokenType::AND;
constexpr JavaTokenType PT_COMMENT = JavaTokenType::COMMENT;
constexpr JavaTokenType PT_COMMENT_START = JavaTokenType::COMMENT_START;
constexpr JavaTokenType PT_COMMENT_END = JavaTokenType::COMMENT_END;

constexpr JavaTokenType PT_IDENTIFIER = JavaTokenType::IDENTIFIER;  
constexpr JavaTokenType PT_INTEGER = JavaTokenType::INTEGER;  
constexpr JavaTokenType PT_REAL = JavaTokenType::REAL; 
constexpr JavaTokenType PT_STRING = JavaTokenType::STRING; 
constexpr JavaTokenType PT_ERROR = JavaTokenType::ERROR;
constexpr JavaTokenType PT_END_OF_FILE = JavaTokenType::END_OF_FILE;

class JavaToken : public Token
{
public:
    static map<string, JavaTokenType> RESERVED_WORDS;
    static map<string, JavaTokenType> SPECIAL_SYMBOLS;
    static map<JavaTokenType, string> SPECIAL_SYMBOL_NAMES;

protected:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    JavaToken(Source *source) throw (string);

private:
    static bool INITIALIZED;

    /**
     * Initialize the static maps.
     */
    static void initialize();
};

}}}  // namespace wci::frontend::Java

#endif /* WCI_FRONTEND_Java_JavaTOKEN_H_ */
