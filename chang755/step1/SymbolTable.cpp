/*
The class for constructing the symbol table.
Symbol table is a map that maps a variable to a key that is a table entry.
*/

#include <iostream>
#include <map>
#include <vector>

#include "TableEntry.h"
#include "SymbolTable.h"

SymbolTable* SymbolTable::uniqueSymbol = NULL;
std::map<std::string, TableEntry>* SymbolTable::symbolMap = NULL;
std::vector<int> SymbolTable::scopes = std::vector<int>();
int SymbolTable::totalLength = 0;

SymbolTable::SymbolTable() {
    this->symbolMap = new std::map<std::string, TableEntry>();
    this->scopes.push_back(0);
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
    if(checkSymbolDuplicate(symbol) >= 1) {
        std::cerr << "Error: Duplicate symbol " << symbol << std::endl;
        return -1;
    }
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

int SymbolTable::checkSymbolDuplicate(std::string symbol) {
    // we peek the top of the scope stack and get the location of the start of the subroutine
    int scopeLoc = scopes.back();

    int count = 0;
    int idx_itr = 0;
    for(std::map<std::string, TableEntry>::iterator it = symbolMap->begin(); it != symbolMap->end(); it++) {
        // if the symbol is in the same scope, we increment the count
        // if seconde.getLocation() >= scopeLoc, then the symbol is in the same scope
        if(idx_itr >= scopeLoc && it->first == symbol) {
            count++;
        }
        idx_itr++;
    }

    return count;
}

/* if a subroutine is triggered, we add a stack to scopes */
void SymbolTable::addNewScope(int scopeLoc) {
    scopes.push_back(scopeLoc);
}

void SymbolTable::popScope() {
    scopes.pop_back();
}