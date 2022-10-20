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

int main(int argc, char **argv) {
    string f_string = argv[1];

    fstream f;
    string line;
    f.open(f_string);

    if(f.is_open()){
        while(getline(f, line)){
            // add all parsed instructions to pre-instruction list first, checking input, etc
            // check if the line is a instruction from the list above.

        }
        // for each item in pre instruction list
        // then go through instruction list and add stuff to symbol table, statement buffer, etc
        // do stuff like assign addresses,
        // check if var has been defined twice
        // add set total num of vars to start
        // etc
        f.close();
    }
    else cout << "Error while opening input file";
    return 0;
}

// reading input file 

// write output file
