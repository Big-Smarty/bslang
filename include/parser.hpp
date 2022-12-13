#pragma once

#include "ast.hpp"

std::vector<char> read_file(std::string file);
std::vector<std::unique_ptr<ExprAST>> parse_file(std::string file);
