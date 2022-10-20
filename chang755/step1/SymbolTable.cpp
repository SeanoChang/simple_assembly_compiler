/*
The class for constructing the symbol table
Basically, it is the stack to store the symbols.
*/

#include <iostream>
#include <string>

#include "SymbolTable.h"

SymbolTable* SymbolTable::uniqueSymbol = NULL;

SymbolTable::SymbolTable() {
    definedMap = new std::map<std::string, long>();
	idx = 0; 
    this->symbol = "";
}

SymbolTable::SymbolTable(std::string symbol) {
    this->symbol = symbol;
}

SymbolTable::~SymbolTable() {
    delete uniqueSymbol;
}

SymbolTable* SymbolTable::getSymbol(std::string symbol) {
    if (uniqueSymbol == NULL) {
        uniqueSymbol = new SymbolTable(symbol);
    }
    return uniqueSymbol;
}



