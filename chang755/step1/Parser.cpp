/*
The parser.cpp is where all the parsing happens. 
It is the main class that calls all the other classes.
*/

#include <fstream>
#include <regex>
#include "Parser.h"
#include "Helpers.h"
#include "SymbolTable.h"
#include "StringBuffer.h"
#include "TableEntry.h"
#include "Instruction.h"
#include "DeclarrStmtOps.h"
#include "DeclscalStmtOps.h"
#include "DecllabelStmtOps.h"
#include "LabelStmtOps.h"
#include "VarStmtOps.h"
#include "IntStmtOps.h"
#include "PrintStmtOps.h"
#include "StmtOps.h"

using namespace std;

int Parser::parse(std::ifstream& infile, std::ofstream& outfile1, std::ofstream& outfile2){
  // populate the instruction buffer for storing the instructions
  InstructionBuffer* ibuf = InstructionBuffer::getInstructionBuffer();
  // populate the symbol table for storing the variables
  SymbolTable* symtab = SymbolTable::getSymbolTable();
  // populate the string buffer for storing the strings
  StringBuffer* sbuf = StringBuffer::getStringBuffer();

  std::string end = "";
  // read the file line by line
  int goSubLabel = 0; // initial size of the goSubLabel
  while(!infile.eof()){
    // read a line
    std::string line;
    getline(infile, line);

    /* check if the line is a valid operation */
    // first break down the line into opcode and variables
    std::regex re1("([a-z]+)");
    std::regex re2("([a-z]+)(\\s[a-zA-Z_0-9\\+=\\*/]+)");
    std::regex re3("([a-z]+)(\\s[a-zA-Z_0-9]+)(\\s[0-9]+$)");
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
    int loc = -2; // empty state for the location

    switch(num_groups){
      case 2: // case for only operation
        validStmt = createInstruction(sm1[1]);
        if(validStmt == NULL){
          std::cerr << "invalid operation" << std::endl;
          return -1;
        } 
        // if the operation is valid, then add it to the instruction buffer.
        ibuf->addToInstructionBuffer(validStmt, loc, "");
        if(sm1[1] == "end"){
          end = "end";
        } else if(sm1[1] == "return"){
          // after returning from the subroutine, we need to pop off the varaibles declared in the subroutine
          // symtab->popVariables();
          // pop off the stack of scope from the symbol table
          goSubLabel = symtab->popScope();
        }

        break;
      case 3: // case for one operation and one variable/string
        validStmt = createInstruction(sm2[1]);
        if(validStmt == NULL){
          std::cerr << "invalid operation" << std::endl;
          return -1;
        }

        // strip the whitespace from the variable

        var1 = sm2[2];
        instruction = sm2[1];
        if(1){
          std::regex re("([a-zA-Z_0-9\\+=\\*/]+)");
          std::smatch sm;
          std::regex_search(var1, sm, re);
          var1 = sm[1];
        }

        // if the operation is declaring a symbol, then add it to the symbol table
        if(instruction == "label"){
          int location = ibuf->getInstructionBufferSize();
          loc = addLabelToSymbolTable(var1, location,  symtab);
        } else if(instruction == "declscal"){
          loc = addScalarToSymbolTable(var1, symtab);
        } else if (instruction == "prints"){
          // if the operation is printing a string, then add it to the string buffer
          loc = addToStringBuffer(var1, sbuf);
        } else if (instruction == "gosublabel"){
          loc = addLabelToSymbolTable(var1, -2, symtab);
          // now entering the subroutine
          // add a new scope to the symbol table
          symtab->addNewScope();
        } else if(instruction == "pushi"){
          loc = stoi(var1);
        } else if(instruction == "popscal" || instruction == "pushscal" || instruction == "pusharr" || instruction == "poparr"){
          loc = symtab->getSymbolTableLocation(var1);
        }

        if(loc == -1){
          std::cerr << "Error adding to buffer... " << std::endl;
          return -1;
        }

        ibuf->addToInstructionBuffer(validStmt, loc, var1);
        break;
      case 4: // case for one operation and two varibles/strings
        validStmt = createInstruction(sm3[1]);
        if(validStmt == NULL){
          std::cerr << "invalid operation" << std::endl;
          return -1;
        } 
        var1 = sm3[2];
        var2 = sm3[3];
        if(1){
          std::regex re("([a-zA-Z_0-9\\+=\\*/]+)");
          std::smatch sm;
          std::regex_search(var1, sm, re);
          var1 = sm[1];
        }
        loc = addArrayToBuffer(var1, var2, symtab);
        if(loc == -1){
          std::cerr << "Error adding to buffer... " << std::endl;
          return -1;
        }
        ibuf->addToInstructionBuffer(validStmt, loc, var1);
        break;
      default:
        break;
    }
  }

  // after reading the the file, check if there is an end statement 
  if(end != "end"){
    std::cerr << "Error: no end statement" << std::endl;
    return -1;
  } else { // condition for stmt after end statement.
    if(ibuf->instBuffer[ibuf->getInstructionBufferSize()-1]->getInstruction() != "Exit"){
      std::cerr << "Error: stmt after end statement" << std::endl;
      return -1;
    }
  }

  /* Print out the instruction buffer and patch things up */
  std::cout << "=====================" << std::endl;

  ibuf->patchUpInstructionBuffer(symtab, goSubLabel);

  ibuf->printInstructionBuffer();
  std::cout << "=====================\n" << std::endl;

  return writeOutputFile(outfile1,outfile2, ibuf, sbuf);
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
int Parser::writeOutputFile(std::ofstream& outfile1, std::ofstream& outfile2, InstructionBuffer* ibuf, StringBuffer* sbuf){
  // write to output file 1
  // print out all the string first
  
  for(int i = 0; i < sbuf->getStrBufferSize(); i++){
    std::string str = sbuf->getString(i);
    outfile1 << str << "\n";
  }

  // print out all the instruction

  for(auto& inst: ibuf->instBuffer){
    std::string str = inst->getInstruction();
    if(inst->getInstructionState() >= 0){
        if(str == "Prints"){
            outfile1 << str << " " << inst->getInstructionState() << "\n";
        } else if(str == "PrintTOS" || str == "Add" || str == "Div" || 
        str == "Return" || str == "Exit" || str == "Dup" || 
        str == "Swap" || str == "Pop" ||
        str == "Mul" || str == "Negate") {
            outfile1 << str << " \n";
        } else{
            outfile1 << str << " " << inst->getInstructionState() << "\n";
        }
    }
  }

  // run through ibuf and write to output file 2
  for (auto& inst: ibuf->instBuffer) {
    std::string str = inst->getInstruction();
    if(inst->getInstructionState() >= 0){
        if(str == "Prints"){
            outfile2 << str << " " << inst->getLabel() << "\n";
        } else if(str == "PrintTOS" || str == "Add" || str == "Div" || 
        str == "Return" || str == "Exit" || str == "Dup" || 
        str == "Swap" || str == "Pop" ||
        str == "Mul" || str == "Negate") {
            outfile2 << str << " \n";
        } else if(str == "GoSub" || str == "PopScalar" || str == "PushScalar" ||
        str == "PushArray" || str == "PopArray" || str == "JumpZero" ||
        str == "JumpNZero") {
            outfile2 << str << " " << inst->getLabel() << " " << inst->getInstructionState()  << "\n";
        } else if(str == "GoSubLabel"){
            outfile2 << str << " " << inst->getLabel() << "\n";
        } else{
            outfile2 << str << " " << inst->getInstructionState() << "\n";
        }
    }
  }
  return 0;
}

