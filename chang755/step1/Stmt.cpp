#include <iostream>

#include "Stmt.h"
using namespace std;

/* Stmt pure virtual destructor */
Stmt::~Stmt() {
    delete takeInputBehavior;
}

void Stmt::setTakeInputBehavior(TakeInputBehavior* _takeInputBehavior) {
   takeInputBehavior = _takeInputBehavior;
}

int Stmt::takeInput(std::string input) {
   return takeInputBehavior->addToBuffer(input);
}

int Stmt::takeInput(std::string input, StringBuffer* stringBuffer) {
    return takeInputBehavior->addToBuffer(input, stringBuffer);
}

int Stmt::takeInput(std::string input, SymbolTable* symbolTable) {
    return takeInputBehavior->addToBuffer(input, symbolTable);
}

int Stmt::takeInput(std::string input1, std::string input2, SymbolTable* symbolTable) {
    return takeInputBehavior->addToBuffer(input1, input2, symbolTable);
}
