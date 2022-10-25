#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <string>
#include <iostream>
#include <map>

/*
The SymbolTable class is a singleton class.
It is used to store the symbol for the entry table.
*/
#include <string>
#include <map>
#include "TableEntry.h"

class SymbolTable{
    public:
        static SymbolTable* getSymbolTable();
        void addToSymbolTable(std::string symbol, TableEntry entry);
        TableEntry getTableEntry(std::string symbol); 
    private:
        static SymbolTable* uniqueSymbol;
        static std::map<std::string, TableEntry>* symbolMap;
        SymbolTable();
        ~SymbolTable();
}; 

#endif 
