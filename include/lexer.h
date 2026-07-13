#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include "token.h"

class Lexer {
public:
    Lexer(const std::string& source);

    char current();
    std::vector<Token> tokenize();

private:
    std::string source;
    size_t pos;

    void advance();
    
    bool isLetter(char c);
    bool isDigit(char c);

    std::string readIdentifier();
    std::string readNumber();

};


#endif