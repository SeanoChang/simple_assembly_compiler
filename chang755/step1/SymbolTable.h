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
        void addToSymbolMap(std::string symbol, TableEntry entry);   
    private:
        static SymbolTable* uniqueSymbol;
        static std::map<std::string, TableEntry>* symbolMap;
        SymbolTable();
        ~SymbolTable();
}; 

#endif 
