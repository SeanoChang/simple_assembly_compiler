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

class SymbolTable{
    public:
        static SymbolTable* getSymbolTable();
        int addToSymbolTable(std::string symbol, TableEntry entry);
        TableEntry getTableEntry(std::string symbol); 
        int getSymbolTableLocation(std::string symbol);
        int getSymbolTableLength();
        int symbolExist(std::string symbol);
        ~SymbolTable();
    private:
        static SymbolTable* uniqueSymbol;
        static std::map<std::string, TableEntry>* symbolMap;
        static int totalLength;
        SymbolTable();
}; 

#endif 
