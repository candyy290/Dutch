#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& source)
    : source(source), pos(0)
{
}

char Lexer::current() {
    if (pos >= source.length()) {
        return '\0';
    }

    return source[pos];
}

void Lexer::advance() {
    pos++;
}

bool Lexer::isLetter(char c) {
    return std::isalpha(static_cast<unsigned char>(c)) || c == '_';
}

bool Lexer::isDigit(char c) {
    return std::isdigit(static_cast<unsigned char>(c));
}

std::string Lexer::readIdentifier() {
    std::string result;
    while (isLetter(current()) || isDigit(current())) {
        result += current();
        advance();
    }
    return result;
}

std::string Lexer::readNumber() {
    std::string result;
    while (isDigit(current())) {
        result += current();
        advance();
    }
    return result;
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (current() != '\0') {

        if(std::isspace(static_cast<unsigned char>(current()))) {
            advance();
            continue;
        }

        if (current()=='(') {
            tokens.push_back({TokenType::LPAREN, "("});
            continue;
        }
        if (current()==')') {
            tokens.push_back({TokenType::RPAREN, ")"});
            continue;
        }
        if (current()=='{') {
            tokens.push_back({TokenType::LBRACE, "{"});
            continue;
        }
        if (current()=='}') {
            tokens.push_back({TokenType::RBRACE, "}"});
            continue;
        }

        if(current()=='=') {
            tokens.push_back({TokenType::EQUAL, "="});
            continue;
        }

        if(current ()==',') {
            tokens.push_back({TokenType::COMMA, ","});
            continue;
        }

         if (isLetter(current())) {

            std::string word = readIdentifier();

            if (word == "dutch") {
                tokens.push_back({TokenType::DUTCH, word});
            }
            else if (word == "let") {
                tokens.push_back({TokenType::LET, word});
            }
            else {
                tokens.push_back({TokenType::IDENTIFIER, word});
            }

            continue;
    }   

    if(isDigit(current())) {
        std::string number = readNumber();
        tokens.push_back({TokenType::NUMBER, number});
        continue;
    }
        //more token types can be added here
        //fffffffkkkkkk
        advance();
    }

    tokens.push_back({TokenType::TOKEN_EOF, ""});

    return tokens;
}

