#include "parser.hpp"
#include <fstream>
#include <memory>
#include <stdio.h>
std::vector<char> read_file(std::string file) {
  std::ifstream source_file(file, std::ios::ate);

  if (!source_file.is_open()) {
    printf("Failed to open: %s", file.c_str());
  }
  size_t size = source_file.tellg();
  source_file.seekg(0);
  std::vector<char> buffer(size / sizeof(char));
  source_file.read(buffer.data(), size);
  source_file.close();
}

std::vector<std::unique_ptr<ExprAST>> parse_file(std::string file) {
  auto source = read_file(file);
}
