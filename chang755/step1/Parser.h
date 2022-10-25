/*
The parser.cpp is where all the parsing happens. 
It is the main class that calls all the other classes.
*/

#ifndef PARSER_H_
#define PARSER_H_
#include <iostream>
#include <string>
#include <vector>
#include "Stmt.h"

static const std::vector<std::string> stmt_ops = { 
  "start",
  "end",
  "exit",
  "return",
  "pop",
  "dup",
  "swap",
  "add",
  "negate",
  "mul",
  "div",
  "printtos",
  "prints"                          
};

static const std::vector<std::string> var_stmt_ops = {
  "declscal",
  "pushscal",
  "pusharr",
  "popscal",
  "poparr"
};

static const std::vector<std::string> int_stmt_ops = {"pushi"};

static const std::vector<std::string> varLen_stmt_ops = {"declarr"};

static const std::vector<std::string> label_stmt_ops ={
  "label",
  "gosublabel",
  "jump",
  "jumpzero",
  "jumpnzero",
  "gosub"
};

static const std::vector<std::vector<std::string>> stmt_ops_list = {
  stmt_ops,
  var_stmt_ops,
  int_stmt_ops,
  varLen_stmt_ops,
  label_stmt_ops
};

class Parser {
    public:
        Parser() {};
        ~Parser() {};
        void parse(std::ifstream& infile, std::ofstream& outfile1, std::ofstream& outfile2);
    private:
        Stmt* createInstruction(std::string op);
};  

#endif /* PARSER_H_ */

