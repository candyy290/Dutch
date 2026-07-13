#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <memory>

#include "lexer.h"
#include "token.h"
#include "ast.h"

class Parser {
public:
    Parser(const std::vector<Token>& tokens);

    std::unique_ptr<ProgramNode> parse();

private:
    std::vector<Token> tokens;
    size_t pos;

    const Token& current();
    void advance();

    bool match(TokenType type);
    Token expect(TokenType type);

    std::unique_ptr<FunctionNode> parseFunction();
    std::unique_ptr<BlockNode> parseBlock();
    std::unique_ptr<Statement> parseStatement();
    std::unique_ptr<Expression> parseExpression();
};

#endif