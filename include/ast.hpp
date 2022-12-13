#pragma once

#include <memory>
#include <string>
#include <vector>

class ExprAST {
public:
  virtual ~ExprAST();
};

class NumberExprAST : public ExprAST {
public:
  NumberExprAST(double value) : value(value) {}

private:
  double value;
};

class VariableExprAST : public ExprAST {
public:
  VariableExprAST(const std::string &name) : name(name) {}

private:
  std::string name;
};

class BinaryExprAST : public ExprAST {
public:
  BinaryExprAST(char op, std::unique_ptr<ExprAST> LHS,
                std::unique_ptr<ExprAST> RHS)
      : op(op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}

private:
  char op;
  std::unique_ptr<ExprAST> LHS, RHS;
};

class CallExprAST : public ExprAST {
public:
  CallExprAST(const std::string &callee,
              std::vector<std::unique_ptr<ExprAST>> args)
      : callee(callee), args(std::move(args)) {}

private:
  std::string callee;
  std::vector<std::unique_ptr<ExprAST>> args;
};

class PrototypeAST {
public:
  PrototypeAST(const std::string &name, std::vector<std::string> args)
      : name(name), args(args) {}

private:
  std::string name;
  std::vector<std::string> args;
};

class FunctionAST {
public:
  FunctionAST(std::unique_ptr<PrototypeAST> proto,
              std::unique_ptr<ExprAST> body)
      : proto(std::move(proto)), body(std::move(body)) {}

private:
  std::unique_ptr<PrototypeAST> proto;
  std::unique_ptr<ExprAST> body;
};
