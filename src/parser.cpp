#include "parser.h"

#include <stdexcept>

Parser::Parser(const std::vector<Token>& tokens)
    : tokens(tokens), pos(0)
{
}

const Token& Parser::current() {
    if (pos >= tokens.size()) {
        throw std::runtime_error("Unexpected end of tokens");
    }
    return tokens[pos];
}

void Parser::advance() {
    if (pos < tokens.size() - 1)
        pos++;
}

bool Parser::match(TokenType type) {
    if (current().type == type) {
        advance();
        return true;
    }
    return false;
}

Token Parser::expect(TokenType type) {
    if (current().type != type) {
        throw std::runtime_error("Unexpected token");
    }

    Token t = current();
    advance();
    return t;
}

std::unique_ptr<ProgramNode> Parser::parse() {

    auto program = std::make_unique<ProgramNode>();

    while (current().type != TokenType::TOKEN_EOF) {
        program->declarations.push_back(parseFunction());
    }

    return program;
}

std::unique_ptr<FunctionNode> Parser::parseFunction() {

    expect(TokenType::DUTCH);

    auto function = std::make_unique<FunctionNode>();

    function->name = expect(TokenType::IDENTIFIER).value;

    expect(TokenType::LPAREN);
    expect(TokenType::RPAREN);

    function->body = parseBlock();

    return function;
}

std::unique_ptr<BlockNode> Parser::parseBlock() {

    expect(TokenType::LBRACE);

    auto block = std::make_unique<BlockNode>();

    while (current().type != TokenType::RBRACE && 
    current().type != TokenType::TOKEN_EOF) {
        block->statements.push_back(parseStatement());
    }

    expect(TokenType::RBRACE);

    return block;
}

std::unique_ptr<Statement> Parser::parseStatement() {

    throw std::runtime_error("Statement parser not implemented.");
}

std::unique_ptr<Expression> Parser::parseExpression() {

    throw std::runtime_error("Expression parser not implemented.");
}

