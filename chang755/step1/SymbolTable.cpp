/*
The class for constructing the symbol table.
Symbol table is a map that maps a variable to a key that is a table entry.
*/

#include <iostream>
#include <map>

#include "SymbolTable.h"

SymbolTable* SymbolTable::uniqueSymbol = NULL;
std::map<std::string, TableEntry>* SymbolTable::symbolMap = NULL;

SymbolTable::SymbolTable() {
    this->symbolMap = new std::map<std::string, TableEntry>();
}

SymbolTable::~SymbolTable() {
    delete symbolMap;
    delete uniqueSymbol;
}

SymbolTable* SymbolTable::getSymbolTable() {
    if (uniqueSymbol == NULL) {
        uniqueSymbol = new SymbolTable();
    }
    return uniqueSymbol;
}

void SymbolTable::addToSymbolTable(std::string symbol, TableEntry entry) {
    (*symbolMap)[symbol] = entry;
}

