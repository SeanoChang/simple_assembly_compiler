#include <iostream>
#include <string>
#include "Helpers.h"

int addToSymbolTable(std::string symbol, SymbolTable* symtab) {
    int location = symtab->getSymbolTableLength();
    return symtab->addToSymbolTable(symbol, TableEntry(location, 1));
}

int addToStringBuffer(std::string symbol, StringBuffer* strbfr) {
    return strbfr->addString(symbol);
}

int addArrayToBuffer(std::string symbol, std::string length, SymbolTable* symtab) {
    int len = stoi(length);
    int location = symtab->getSymbolTableLength();
    return symtab->addToSymbolTable(symbol, TableEntry(location, len));
}
