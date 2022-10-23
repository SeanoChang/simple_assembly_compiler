/*
The parser.cpp is where all the parsing happens. 
It is the main class that calls all the other classes.
*/

#include <iostream>
#include <fstream>
#include <regex>
#include "Parser.h"
using namespace std;

static const std::vector<std::string> stmt_ops
{ 
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

static const std::vector<std::string> var_stmt_ops
{
  "declscal",
  "pushscal",
  "pusharr",
  "popscal",
  "poparr"
};

static const std::vector<std::string> int_stmt_ops{"pushi"};

static const std::vector<std::string> varLen_stmt_ops{"declarr"};

static const std::vector<std::string> label_stmt_ops
{
  "label",
  "gosublabel",
  "jump",
  "jumpzero",
  "jumpnzero",
  "gosub"
};



// reading input file 

// write output file
