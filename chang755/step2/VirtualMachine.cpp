/*
Virtual Machine class.
Description: This class will take the input from the file and store it in the instruction memory.
The input file first starts with the strings and then the instructions.
We first read in all the strings if needed and store them in the string table.
Then we read in the instructions and store them in the instruction memory.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#include "VirtualMachine.h"

VirtualMachine::VirtualMachine(){
    instMem = new InstructionMemory();
    dataMem = new DataMemory();
    strTable = new StringTable();
    runStack = new RuntimeStack();
    std::vector<std::string> results = std::vector<std::string>();
}

VirtualMachine::~VirtualMachine(){
    delete instMem;
    delete dataMem;
    delete strTable;
    delete runStack;
}

int VirtualMachine::run(std::ifstream& infile, std::ofstream& outfile){
    /* step 1 read all the lines and put them into the string buffer or instruction memory */
    readToBuffers(infile);

    /* step2  do the instructions,
        result will be store in a vector of strings(messages) => results to be printed */
    processInstructions();

    /* step3 write the result to the output file */
    writeOutput(outfile);

    return 0;
}

/* checking if the operation is valid and return the type of vector it belongs too */
Stmt* VirtualMachine::createInstruction(std::string op) {
  // if the op is a valid operation, then create the stmt object
  if(op.compare("Start") == 0){
    Stmt* stmt = new Opstartprogram();
    return stmt;
  } 
  if(op.compare("Exit") == 0){
    Stmt* stmt = new Opexitprogram();
    return stmt;
  }
  if(op.compare("Return") == 0){
    Stmt* stmt = new Opreturn();
    return stmt;
  }
  if(op.compare("Pop") == 0){
    Stmt* stmt = new Oppop();
    return stmt;
  }
  if(op.compare("Dup") == 0){
    Stmt* stmt = new Opdup();
    return stmt;
  }
  if(op.compare("Swap") == 0){
    Stmt* stmt = new Opswap();
    return stmt;
  }
  if(op.compare("Add") == 0){
    Stmt* stmt = new Opadd();
    return stmt;
  }
  if(op.compare("Negate") == 0){
    Stmt* stmt = new Opnegate();
    return stmt;
  }
  if(op.compare("Mul") == 0){
    Stmt* stmt = new Opmul();
    return stmt;
  }
  if(op.compare("Div") == 0){
    Stmt* stmt = new Opdiv();
    return stmt;
  }
  if(op.compare("PrintTOS") == 0){
    Stmt* stmt = new Opprinttos();
    return stmt;
  }
  if(op.compare("Prints") == 0){
    Stmt* stmt = new Opprints();
    return stmt;
  }
  if(op.compare("PushScalar") == 0){
    Stmt* stmt = new Oppushscalar();
    return stmt;
  }
  if(op.compare("PushArray") == 0){
    Stmt* stmt = new Oppusharray();
    return stmt;
  }
  if(op.compare("PopScalar") == 0){
    Stmt* stmt = new Oppopscalar();
    return stmt;
  }
  if(op.compare("PopArray") == 0){
    Stmt* stmt = new Oppoparray();
    return stmt;
  }
  if(op.compare("PushI") == 0){
    Stmt* stmt = new Oppushi();
    return stmt;
  }
  if(op.compare("GoSubLabel") == 0){
    Stmt* stmt = new Opgosublabel();
    return stmt;
  }
  if(op.compare("Jump") == 0){
    Stmt* stmt = new Opjump();
    return stmt;
  } 
  if(op.compare("Jumpzero") == 0){
    Stmt* stmt = new Opjumpzero();
    return stmt;
  }
  if(op.compare("Jumpnzero") == 0){
    Stmt* stmt = new Opjumpnzero();
    return stmt;
  }
  if(op.compare("Gosub") == 0){
    Stmt* stmt = new Opgosub();
    return stmt;
  }
  // if the op is not a valid operation, then return NULL
  return NULL;
}

int VirtualMachine::readToBuffer(ifstream& infile){
    std::string line;
    if(infile.eof()){ // if the file is empty
        return -1;
    }
    
    while(!infile.eof()){
        getline(infile, line);
        /* check if the line is a valid operation */
        // first break down the line into opcode and variables
        std::regex re1("([a-zA-Z_0-9\\+=\\*/]+)");
        std::regex re2("([a-z]+)(\\s[a-zA-Z_0-9])");
        std::smatch sm1;
        std::smatch sm2;
        std::regex_search(line, sm1, re1);
        std::regex_search(line, sm2, re2);
        
        // regex will split the line into multiple groups
        // determine the number of groups
        int num_groups = sm2.size() == 0 ? sm1.size() : sm2.size();
        // initialize the variables used in the switch statement
        std::string var1;
        Stmt* validStmt = NULL;
        std::string instruction = "";
        int loc = -2; // empty state for the location

        if(num_groups == 1){
            instruction = sm1[0];
            validStmt = createInstruction(instruction);
            if(validStmt != NULL){
                instMem->addInstruction(validStmt);
            } else { // if it is null, then it is a string
                strTable->addString(sm1[0]);
            }
        } else if(num_groups == 2){
            instruction = sm2[0];
            var1 = sm2[1];
            int value = stoi(var1);
            // add to instruction memory
            validStmt = createInstruction(instruction);
        }
    }

    return 0;
}

int VirtualMachine::processInstructions(){
    std::vector<int> returnAddress = std::vector<int>(); // store the return address

    // initialize the program counter
    int pc = 0; // program counter

    int size = instMem->getSize();
    while(pc < size){
        std::string instruction = instMem->getInstruction(pc);
        int state = instMem->getState(pc);
        if(isntruction == "Start"){
            dataMemory.push_back(state);
            pc++;
        } else if(instruction == "Exit"){
            pc++;
        } else if(instruction == "Return"){
            pc = returnAddress.back();
            returnAddress.pop_back();
        } else if(instruction == "Pop"){
            runStack.pop();
            pc++;
        } else if(instruction == "Dup"){
            int top = runStack.peek();
            runStack.push(top);
            pc++;
        } else if(instruction == "Swap"){
            int top = runStack.pop();
            int second = runStack.pop();
            runStack.push(top);
            runStack.push(second);
            pc++;
        } else if(instruction == "Add"){
            int top = runStack.pop();
            int second = runStack.pop();
            runStack.push(top + second);
            pc++;
        } else if(instruction == "Negate"){
            int top = runStack.pop();
            runStack.push(-top);
            pc++;
        } else if(instruction == "Mul"){
            int top = runStack.pop();
            int second = runStack.pop();
            runStack.push(top * second);
            pc++;
        } else if(instruction == "Div"){
            int top = runStack.pop();
            int second = runStack.pop();
            runStack.push(second / top);
            pc++;
        } else if(instruction == "PushScalar"){
            int top = runStack.pop();
            dataMem.setDataAtLocation(state, top);
            pc++;
        } else if(instruction == "PushArray"){

            pc++;
        } else if(instruction == "PopScalar"){
            int top = dataMem.getDataAtLocation(state);
            runStack.push(top);
            pc++;
        } else if(instruction == "PopArray"){
            pc++;
        } else if(instruction == "PushI"){
            runStack.push(state);
            pc++;
        } else if(instruction == "GoSubLabel"){
            dataMem.addNewScope(); // initialize a new scope with state size??
            pc++;
        } else if(instruction == "Jump"){
            pc = state;
        } else if(instruction == "Jumpzero"){
            int top = runStack.pop();
            if(top == 0){
                pc = state;
            } else {
                pc++;
            }
        } else if(instruction == "Jumpnzero"){
            int top = runStack.pop();
            if(top != 0){
                pc = state;
            } else {
                pc++;
            }
        } else if(instruction == "GoSub"){ // enter sub routine push value to return address
            pc = state;
            returnAddress.push_back(pc-1); // return to the instruction prior to the goSubLabel
        } else if(instruction == "Prints"){
            results.push_back(strTable->getString(state));
            pc++;
        } else if(instruction == "PrintTOS"){ // print from top of the stack
            results.push_back(std::to_string(dataMem->pop()));
            pc++;
        } else if(instruction == "Return") {
            pc = returnAddress.back();
            returnAddress.pop_back();
        }
    }
}
