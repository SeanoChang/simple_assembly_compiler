#include <iostream>
#include <string>
#include "Helpers.h"

int addScalarToSymbolTable(std::string symbol, SymbolTable* symtab) {
    int location = symtab->getSymbolTableLength();
    return symtab->addToSymbolTable(symbol, TableEntry(location, 1));
}

int addLabelToSymbolTable(std::string symbol, int location, SymbolTable* symtab) {
    return symtab->addToSymbolTable(symbol, TableEntry(location, 0));
}

int addToStringBuffer(std::string symbol, StringBuffer* strbfr) {
    return strbfr->addString(symbol);
}

int addArrayToBuffer(std::string symbol, std::string length, SymbolTable* symtab) {
    int len = stoi(length);
    int location = symtab->getSymbolTableLength();
    return symtab->addToSymbolTable(symbol, TableEntry(location, len));
}
