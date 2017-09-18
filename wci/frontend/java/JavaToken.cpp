/**
  * <h1>JavaToken</h1>
  *
  * <p>Base class for Java token classes.</p>
  *
  * <p>Copyright (c) 2017 by Ronald Mak</p>
  * <p>For instructional purposes only.  No warranties.</p>
  */
#include <string>
#include <vector>
#include <map>
#include "JavaToken.h"

namespace wci { namespace frontend { namespace java {

using namespace std;

map<string, JavaTokenType> JavaToken::RESERVED_WORDS;
map<string, JavaTokenType> JavaToken::SPECIAL_SYMBOLS;
map<JavaTokenType, string> JavaToken::SPECIAL_SYMBOL_NAMES;

bool JavaToken::INITIALIZED = false;

void JavaToken::initialize()
{
    if (INITIALIZED) return;

    vector<string> rw_strings =
    {
        "abstract", "double", "int", "long", "break", "else", "switch", "case",
        "enum", "native", "super", "char", "extends", "return", "this", "class",
        "float", "short", "throw", "const", "for", "package", "void", "continue",
        "goto", "protected", "volatile", "do", "if", "static", "while"
    };

    vector<JavaTokenType> rw_keys =
    {
        JavaTokenType::ABSTRACT,
        JavaTokenType::DOUBLE,
        JavaTokenType::INTEGER,
        JavaTokenType::LONG_INT,
        JavaTokenType::BREAK,
        JavaTokenType::ELSE,
        JavaTokenType::SWITCH,
        JavaTokenType::CASE,

        JavaTokenType::ENUM,
        JavaTokenType::NATIVE,
        JavaTokenType::SUPER,
        JavaTokenType::CHARACTER,
        JavaTokenType::EXTENDS,
        JavaTokenType::RETURN,
        JavaTokenType::THIS,
        JavaTokenType::CLASS,

        JavaTokenType::FLOAT,
        JavaTokenType::SHORT,
        JavaTokenType::THROW,
        JavaTokenType::CONST,
        JavaTokenType::FOR,
        JavaTokenType::PACKAGE,
        JavaTokenType::VOID,
        JavaTokenType::CONTINUE,

        JavaTokenType::GOTO,
        JavaTokenType::PROTECTED,
        JavaTokenType::VOLATILE,
        JavaTokenType::DO,
        JavaTokenType::IF,
        JavaTokenType::STATIC,
        JavaTokenType::WHILE
    };

    for (unsigned int i = 0; i < rw_strings.size(); i++)
    {
        RESERVED_WORDS[rw_strings[i]] = rw_keys[i];
    }

    vector<string> ss_strings =
    {
        "~", "!", "@", "%", "^", "&", "*", "-", "+", "=", "|", "/", ":", ";", "?", "<", ">", ".", ",", "'", "\"", "(", ")", "[", "]", "{", "}", "++", "--", "<<", ">>", "<=", ">=", "+=", "-=", "*=", "/=", "==", "|=", "%=", "&=", "^=", "!=", "<<=", ">>=", "||", "&&", "//", "/*", "*/"
    };
    
    vector<JavaTokenType> ss_keys =
    {
        JavaTokenType::TILDE,
        JavaTokenType::NOT,
        JavaTokenType::AT,
        JavaTokenType::MODULE,
        JavaTokenType::BIT_XOR,
        JavaTokenType::BIT_AND,
        JavaTokenType::MULT,
        JavaTokenType::MINUS,
        JavaTokenType::PLUS,
        JavaTokenType::EQUAL,
        JavaTokenType::BIT_OR,
        JavaTokenType::DIVIDE,
        JavaTokenType::COLON,
        JavaTokenType::SEMICOLON,
        JavaTokenType::QUESTIONMARK,
        JavaTokenType::LESS_THAN,
        JavaTokenType::GREATER_THAN,
        JavaTokenType::DOT,
        JavaTokenType::COMMA,
        JavaTokenType::SINGLE_QUOTE,
        JavaTokenType::DOUBLE_QUOTE,
        JavaTokenType::LEFT_PAREN,
        JavaTokenType::RIGHT_PAREN,
        JavaTokenType::LEFT_BRACKET,
        JavaTokenType::RIGHT_BRACKET,
        JavaTokenType::LEFT_BRACE,
        JavaTokenType::RIGHT_BRACE,
        JavaTokenType::INCREMENT,
        JavaTokenType::DECREMENT,
        JavaTokenType::SHIFT_LEFT,
        JavaTokenType::SHIFT_RIGHT,
        JavaTokenType::LESS_EQUALS,
        JavaTokenType::GREATER_EQUALS,
        JavaTokenType::PLUS_ASSIGN,
        JavaTokenType::MINUS_ASSIGN,
        JavaTokenType::MULT_ASSIGN,
        JavaTokenType::DIVIDE_ASSIGN,
        JavaTokenType::COMPARE,
        JavaTokenType::BIT_OR_ASSIGN,
        JavaTokenType::MODULE_ASSIGN,
        JavaTokenType::BIT_XOR_ASSIGN,
        JavaTokenType::NOT_EQUALS,
        JavaTokenType::SHIFT_LEFT_ASSIGN,
        JavaTokenType::SHIFT_RIGHT_ASSIGN,
        JavaTokenType::OR,
        JavaTokenType::AND,
		JavaTokenType::COMMENT,
        JavaTokenType::COMMENT_START,
        JavaTokenType::COMMENT_END

    };

    for (unsigned int i = 0; i < ss_strings.size(); i++)
    {
        SPECIAL_SYMBOLS[ss_strings[i]] = ss_keys[i];
    }

    vector<string> ss_names =
    {
         "TILDE", "NOT", "AT", "MODULE", "BIT_XOR", "BIT_AND", "MULT", "MINUS", "PLUS", "EQUAL", "BIT_OR", "DIVIDE", "COLON", "SEMICOLON", "QUESTIONMARK", "LESS_THAN", "GREATER_THAN", "DOT", "COMMA", "SINGLE_QUOTE", "DOUBLE_QUOTE", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_BRACE", "RIGHT_BRACE", "INCREMENT", "DECREMENT", "SHIFT_LEFT", "SHIFT_RIGHT", "LESS_EQUALS", "GREATER_EQUALS", "PLUS_ASSIGN", "MINUS_ASSIGN", "MULT_ASSIGN", "DIVIDE_ASSIGN", "COMPARE", "BIT_OR_ASSIGN", "MODULE_ASSIGN", "BIT_XOR_ASSIGN", "NOT_EQUALS", "SHIFT_LEFT_ASSIGN", "SHIFT_RIGHT_ASSIGN", "OR", "AND", "COMMENT", "COMMENT_START", "COMMENT_END"
    };

    for (unsigned int i = 0; i < ss_names.size(); i++)
    {
        SPECIAL_SYMBOL_NAMES[ss_keys[i]] = ss_names[i];
    }

    INITIALIZED = true;
}

JavaToken::JavaToken(Source *source) throw (string)
    : Token(source)
{
    initialize();
}

}}}  // namespace wci::frontend::Java
