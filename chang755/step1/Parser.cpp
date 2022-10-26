/*
The parser.cpp is where all the parsing happens. 
It is the main class that calls all the other classes.
*/

#include <fstream>
#include <regex>
#include "Parser.h"
#include "TakeInputBehavior.h"
#include "Stmt.h"
#include "SymbolTable.h"
#include "StringBuffer.h"
#include "TableEntry.h"
#include "Instruction.h"

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


    // initialize the variables used in the switch statement
    std::string var1;
    std::string var2;
    Stmt* validStmt = NULL;
    std::string instruction = "";
    int loc = 0;

    switch(num_groups){
      case 2: // case for only operation
        validStmt = createInstruction(sm1[1]);
        std::cout << sm1[1] << std::endl;
        if(validStmt == NULL){
          std::cout << "invalid operation" << std::endl;
          return;
        } 
        // if the operation is valid, then add it to the instruction buffer.
        ibuf->addToInstructionBuffer(validStmt, -1, "");

        break;
      case 3: // case for one operation and one variable/string
        validStmt = createInstruction(sm2[1]);
        std::cout << sm2[1] << std::endl;
        if(validStmt == NULL){
          std::cout << "invalid operation" << std::endl;
          return;
        } 
        var1 = sm2[2];
        instruction = sm2[1];

        if(std::count(print_ops.begin(), print_ops.end(), instruction)) {
          loc = validStmt->takeInput(var1, sbuf);
        } else if (std::count(int_stmt_ops.begin(), int_stmt_ops.end(), instruction)) {
          loc = validStmt->takeInput(var1);
        } else if(std::count(var_stmt_ops.begin(), var_stmt_ops.end(), instruction)) {
          loc = validStmt->takeInput(var1, symtab);
        } else if(std::count(declscal_stmt_ops.begin(), declscal_stmt_ops.end(), instruction)) {
          loc = validStmt->takeInput(var1, symtab);
        } else if(std::count(decllabel_stmt_ops.begin(), decllabel_stmt_ops.end(), instruction)) {
          loc = validStmt->takeInput(var1, symtab);
        } else if(std::count(label_stmt_ops.begin(), label_stmt_ops.end(), instruction)) {
          loc = validStmt->takeInput(var1, symtab);
        }


        ibuf->addToInstructionBuffer(validStmt, loc, var1);
        break;
      case 4: // case for one operation and two varibles/strings
        validStmt = createInstruction(sm3[1]);
        std::cout << sm3[1]<< std::endl;
        if(validStmt == NULL){
          std::cout << "invalid operation" << std::endl;
          return;
        } 
        var1 = sm3[2];
        var2 = sm3[3];
        loc = validStmt->takeInput(var1, var2, symtab);
        ibuf->addToInstructionBuffer(validStmt, loc, var1);
        break;
      default:
        break;
    }
  }
  std::cout << "=====================" << std::endl;
  ibuf->printInstructionBuffer();

  for(auto& inst: ibuf->instBuffer){
    if(inst->getInstructionState() == -1){ // if the instruction is not patched up
      std::string tempLabel = inst->getLabel();
      if(tempLabel != ""){
        int loc = symtab->getSymbolTableLocation(tempLabel);
        inst->setInstructionState(loc);
      } else {
        int loc = symtab->getSymbolTableLength();
        inst->setInstructionState(loc);
      }
    }
  }

  ibuf->printInstructionBuffer();
}

/* checking if the operation is valid and return the type of vector it belongs too */
Stmt* Parser::createInstruction(std::string op) {
  // if the op is a valid operation, then create the stmt object
  if(op.compare("start") == 0){
    Stmt* stmt = new Opstartprogram();
    return stmt;
  } 
  if(op.compare("end") == 0){
    Stmt* stmt = new Opendprogram();
    return stmt;
  }
  if(op.compare("exit") == 0){
    Stmt* stmt = new Opexitprogram();
    return stmt;
  }
  if(op.compare("return") == 0){
    Stmt* stmt = new Opreturn();
    return stmt;
  }
  if(op.compare("pop") == 0){
    Stmt* stmt = new Oppop();
    return stmt;
  }
  if(op.compare("dup") == 0){
    Stmt* stmt = new Opdup();
    return stmt;
  }
  if(op.compare("swap") == 0){
    Stmt* stmt = new Opswap();
    return stmt;
  }
  if(op.compare("add") == 0){
    Stmt* stmt = new Opadd();
    return stmt;
  }
  if(op.compare("negate") == 0){
    Stmt* stmt = new Opnegate();
    return stmt;
  }
  if(op.compare("mul") == 0){
    Stmt* stmt = new Opmul();
    return stmt;
  }
  if(op.compare("div") == 0){
    Stmt* stmt = new Opdiv();
    return stmt;
  }
  if(op.compare("printtos") == 0){
    Stmt* stmt = new Opprinttos();
    return stmt;
  }
  if(op.compare("prints") == 0){
    Stmt* stmt = new Opprints();
    return stmt;
  }
  if(op.compare("declscal") == 0){
    Stmt* stmt = new Opdeclscalar();
    return stmt;
  }
  if(op.compare("pushscal") == 0){
    Stmt* stmt = new Oppushscalar();
    return stmt;
  }
  if(op.compare("pusharr") == 0){
    Stmt* stmt = new Oppusharray();
    return stmt;
  }
  if(op.compare("popscal") == 0){
    Stmt* stmt = new Oppopscalar();
    return stmt;
  }
  if(op.compare("poparr") == 0){
    Stmt* stmt = new Oppoparray();
    return stmt;
  }
  if(op.compare("pushi") == 0){
    Stmt* stmt = new Oppushi();
    return stmt;
  }
  if(op.compare("declarr") == 0){
    Stmt* stmt = new Opdeclarray();
    return stmt;
  }
  if(op.compare("label") == 0){
    Stmt* stmt = new Oplabel();
    return stmt;
  }
  if(op.compare("gosublabel") == 0){
    Stmt* stmt = new Opgosublabel();
    return stmt;
  }
  if(op.compare("jump") == 0){
    Stmt* stmt = new Opjump();
    return stmt;
  } 
  if(op.compare("jumpzero") == 0){
    Stmt* stmt = new Opjumpzero();
    return stmt;
  }
  if(op.compare("jumpnzero") == 0){
    Stmt* stmt = new Opjumpnzero();
    return stmt;
  }
  if(op.compare("gosub") == 0){
    Stmt* stmt = new Opgosub();
    return stmt;
  }
  // if the op is not a valid operation, then return NULL
  return NULL;
}

// write output file
int Parser::writeOutputFile(std::ofstream& outfile1, std::ofstream& outfile2, InstructionBuffer* ibuf){
  for(auto& inst: ibuf->instBuffer){
    outfile1 << inst->getInstruction() << " " << inst->getInstructionState() << std::endl;
    outfile2 << inst->getInstruction() << " " << inst->getInstructionState()<< std::endl;
  }
  return 0;
}

