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
std::vector<std::map<std::string, TableEntry>> SymbolTable::symbolMaps = std::vector<std::map<std::string, TableEntry>>();
int SymbolTable::totalLength = 0;
int SymbolTable::scopes = 0;

SymbolTable::SymbolTable() {
    symbolMaps.reserve(10);
    symbolMaps.push_back(std::map<std::string, TableEntry>());
}

SymbolTable::~SymbolTable() {
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
    // check if there is a new scope
    symbolMaps[scopes][symbol] = entry;
    totalLength += entry.getLength();
    return entry.getLocation();
}

int SymbolTable::getSymbolTableLocation(std::string symbol) {
    return symbolMaps[scopes][symbol].getLocation();
}

int SymbolTable::getSymbolTableLength() {
    return totalLength;
}

int SymbolTable::checkSymbolDuplicate(std::string symbol) {
    return symbolMaps[scopes].count(symbol);
}

/* if a subroutine is triggered, we add a stack to scopes */
void SymbolTable::addNewScope() {
    scopes++;
    symbolMaps.push_back(std::map<std::string, TableEntry>());
}

void SymbolTable::popScope() {
    // delete the symbol map first
    scopes--;
}