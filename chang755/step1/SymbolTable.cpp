/*
The class for constructing the symbol table.
Symbol table is a map that maps a variable to a key that is a table entry.
*/

#include <iostream>
#include <map>

#include "TableEntry.h"
#include "SymbolTable.h"

SymbolTable* SymbolTable::uniqueSymbol = NULL;
std::map<std::string, TableEntry>* SymbolTable::symbolMap = NULL;
int SymbolTable::totalLength = 0;

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

int SymbolTable::addToSymbolTable(std::string symbol, TableEntry entry) {
    (*symbolMap)[symbol] = entry;
    totalLength += entry.getLength();
    return entry.getLocation();
}

int SymbolTable::getSymbolTableLocation(std::string symbol) {
    return (*symbolMap)[symbol].getLocation();
}

int SymbolTable::getSymbolTableLength() {
    return totalLength;
}

int SymbolTable::symbolExist(std::string symbol) {
    return symbolMap->count(symbol);
}
