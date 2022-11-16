#ifndef PARSER_H_
#define PARSER_H_
#include <iostream>
#include <string>
#include <vector>
#include "Stmt.h"
#include "InstructionBuffer.h"

static const std::vector<std::string> stmt_ops = { //ib
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
  "printtos",
  "div"                        
};

static const std::vector<std::string> print_ops = { //string buffer 
  "prints"                          
};

static const std::vector<std::string> var_stmt_ops = { //ib
  "pushscal",
  "pusharr",
  "popscal",
  "poparr"
};

static const std::vector<std::string> int_stmt_ops = {"pushi"}; //ib

static const std::vector<std::string> declscal_stmt_ops = {"declscal"}; //st

static const std::vector<std::string> declarr_stmt_ops = {"declarr"}; //st

static const std::vector<std::string> decllabel_stmt_ops = {
  "label",
  "gosublabel"
}; //ib

static const std::vector<std::string> label_stmt_ops ={ //st
  "jump",
  "jumpzero",
  "jumpnzero",
  "gosub"
};

static const std::vector<std::vector<std::string>> stmt_ops_list = { //??
  stmt_ops,
  var_stmt_ops,
  int_stmt_ops,
  declscal_stmt_ops,
  declarr_stmt_ops,
  decllabel_stmt_ops,
  label_stmt_ops
};

class Parser {
    public:
        Parser() {};
        ~Parser() {};
        int parse(std::ifstream& infile, std::ofstream& outfile1, std::ofstream& outfile2);
    private:
        Stmt* createInstruction(std::string op);
        int writeOutputFile(std::ofstream& outfile1, std::ofstream& outfile2, InstructionBuffer* ibuf, StringBuffer* sbuf);
};  

#endif /* PARSER_H_ */
