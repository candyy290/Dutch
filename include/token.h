#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    DUTCH,
    IDENTIFIER,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    TOKEN_EOF,
    LET,
    NUMBER,
    STRING,
    EQUAL,
    COMMA
};

struct Token {
    TokenType type;
    std::string value;

};

#endif