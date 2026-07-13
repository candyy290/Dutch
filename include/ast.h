#ifndef AST_H
#define AST_H

#include <memory>
#include <string>
#include <vector>
#include "token.h"

class Statement;
class Expression;   
class BlockNode;
class ParameterNode;

class ASTNode {
public:
    virtual ~ASTNode() = default;
};

class Statement : public ASTNode {
};

class Expression : public ASTNode {
};

class DeclarationNode : public ASTNode {
};

class ProgramNode : public ASTNode {
public:
    std::vector<std::unique_ptr<DeclarationNode>> declarations;
};

class FunctionNode : public DeclarationNode {
public:
    std::string name;

    std::vector<std::unique_ptr<ParameterNode>> parameters;
    std::unique_ptr<BlockNode> body;
};

class BlockNode : public Statement {
public:
    std::vector<std::unique_ptr<Statement>> statements;
};

class LetNode : public Statement {
public:
    std::string name;

    std::unique_ptr<Expression> value;
};

class ReturnNode : public Statement {
public:
    std::unique_ptr<Expression> value;
};

class CallNode : public Expression {
public:
    std::string name;
    std::vector<std::unique_ptr<Expression>> arguments;
};

class BinaryExpression: public Expression {
public:
    TokenType op;
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
};

class IdentifierNode : public Expression {
public:
    std::string name;
};

class BooleanNode : public Expression {
public:
    bool value;
};

class UnaryExpression : public Expression {
public:
    TokenType op;
    std::unique_ptr<Expression> expr;
};

class NumberNode : public Expression {
public:
    std::string value;
};

class StringNode : public Expression {
public:
    std::string value;
};

class IfNode : public Statement {
public:
    std::unique_ptr<Expression> condition;
    std::unique_ptr<BlockNode> thenBlock;
    std::unique_ptr<BlockNode> elseBlock;
};

class WhileNode : public Statement {
public:
    std::unique_ptr<Expression> condition;
    std::unique_ptr<BlockNode> body;
};

class ForNode : public Statement {
public:
    std::unique_ptr<Statement> init;
    std::unique_ptr<Expression> condition;
    std::unique_ptr<Statement> increment;
    std::unique_ptr<BlockNode> body;
};

class AssignmentNode : public Statement {
public:            
    std::string name;
    std::unique_ptr<Expression> target;
    std::unique_ptr<Expression> value;
};  

class MemberAccessNode : public Expression {
public:
    std::unique_ptr<Expression> object;
    std::string property;
};

class ParameterNode : public ASTNode {
public:
    std::string name;
};



#endif