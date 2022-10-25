/*
The parser.cpp is where all the parsing happens. 
It is the main class that calls all the other classes.
*/

#include <fstream>
#include <regex>
#include "Parser.h"
#include "Stmt.h"
#include "SymbolTable.h"
#include "StringBuffer.h"
#include "TableEntry.h"
#include "Instruction.h"
#include "InstructionBuffer.h"
using namespace std;

void Parser::parse(std::ifstream& infile, std::ofstream& outfile1, std::ofstream& outfile2){
  // populate the instruction buffer for storing the instructions
  InstructionBuffer* ibuf = InstructionBuffer::getInstructionBuffer();
  // populate the symbol table for storing the variables
  SymbolTable* symtab = SymbolTable::getSymbolTable();
  // populate the string buffer for storing the strings
  StringBuffer* sbuf = StringBuffer::getStringBuffer();


  while(!infile.eof()){
    // read a line
    std::string line;
    getline(infile, line);

    /* check if the line is a valid operation */
    // first break down the line into opcode and variables
    std::regex re1("([a-z]+)");
    std::regex re2("([a-z]+)(\\s[a-zA-Z_0-9]*)");
    std::regex re3("([a-z]+)(\\s[a-zA-Z_0-9]*)(\\s[a-zA-Z_0-9]*)");
    std::smatch sm1;
    std::smatch sm2;
    std::smatch sm3;
    std::regex_search(line, sm1, re1);
    std::regex_search(line, sm2, re2);
    std::regex_search(line, sm3, re3);
    // regex will split the line into multiple groups
    // determine the number of groups
    int num_groups = sm3.size() == 0 ? (sm2.size() == 0 ? sm1.size() : sm2.size()) : sm3.size();


    Stmt* validStmt = NULL;
    switch(num_groups){
      case 2: // case for only operation
        std::cout << "input: " << sm1[0] << std::endl;
        validStmt = createInstruction(sm1[1]);
        if(validStmt == NULL){
          std::cout << "invalid operation" << std::endl;
          return;
        } 
        // if the operation is valid, then add it to the instruction buffer.
        ibuf->addInstruction((Instruction*)validStmt);

        break;
      case 3: // case for one operation and one variable/string
        std::cout << "input: " << sm2[0] << std::endl;
        validStmt = createInstruction(sm2[1]);
        if(validStmt == NULL){
          std::cout << "invalid operation" << std::endl;
          return;
        } 
        
      
        break;
      case 4: // case for one operation and two varibles/strings
        std::cout << "input: " << sm3[0] << std::endl;
        validStmt = createInstruction(sm3[1]);
        if(validStmt == NULL){
          std::cout << "invalid operation" << std::endl;
          return;
        } 
        
        break;
      default:
        break;
    }
  }
}

/* checking if the operation is valid and return the type of vector it belongs too */
Stmt* Parser::createInstruction(std::string op) {
  // if the op is a valid operation, then create the stmt object
  if(op.compare("start")){
    Stmt* stmt = new Opstartprogram();
    return stmt;
  } 
  if(op.compare("end")){
    Stmt* stmt = new Opendprogram();
    return stmt;
  }
  if(op.compare("exit")){
    Stmt* stmt = new Opexit();
    return stmt;
  }
  if(op.compare("return")){
    Stmt* stmt = new Opreturn();
    return stmt;
  }
  if(op.compare("pop")){
    Stmt* stmt = new Oppop();
    return stmt;
  }
  if(op.compare("dup")){
    Stmt* stmt = new Opdup();
    return stmt;
  }
  if(op.compare("swap")){
    Stmt* stmt = new Oppush();
    return stmt;
  }
  if(op.compare("add")){
    Stmt* stmt = new Opadd();
    return stmt;
  }
  if(op.compare("negate")){
    Stmt* stmt = new Opnegate();
    return stmt;
  }
  if(op.compare("mul")){
    Stmt* stmt = new Opmul();
    return stmt;
  }
  if(op.compare("div")){
    Stmt* stmt = new Opdiv();
    return stmt;
  }
  if(op.compare("printtos")){
    Stmt* stmt = new Opprinttos();
    return stmt;
  }
  if(op.compare("prints")){
    Stmt* stmt = new Opprints();
    return stmt;
  }
  if(op.compare("declscal")){
    Stmt* stmt = new Opdeclscal();
    return stmt;
  }
  if(op.compare("pushscal")){
    Stmt* stmt = new Oppushscal();
    return stmt;
  }
  if(op.compare("pusharr")){
    Stmt* stmt = new Oppusharr();
  }
  if(op.compare("popscal")){
    Stmt* stmt = new Oppopscal();
    return stmt;
  }
  if(op.compare("poparr")){
    Stmt* stmt = new Oppoparr();
    return stmt;
  }
  if(op.compare("pushi")){
    Stmt* stmt = new Oppushi();
    return stmt;
  }
  if(op.compare("declarr")){
    Stmt* stmt = new Opdeclarr();
    return stmt;
  }
  if(op.compare("label")){
    Stmt* stmt = new Oplabel();
  }
  if(op.compare("gosublabel")){
    Stmt* stmt = new Opgosublabel();
    return stmt;
  }
  if(op.compare("jump")){
    Stmt* stmt = new Opjump();
    return stmt;
  } 
  if(op.compare("jumpzero")){
    Stmt* stmt = new Opjumpzero();
    return stmt;
  }
  if(op.compare("jumpnzero")){
    Stmt* stmt = new Opjumpnzero();
    return stmt;
  }
  if(op.compare("gosub")){
    Stmt* stmt = new Opgosub();
    return stmt;
  }
  // if the op is not a valid operation, then return NULL
  return NULL;
}

// write output file
