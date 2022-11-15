#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <string>
#include <iostream>
#include <map>
#include <vector>

/*
The SymbolTable class is a singleton class.
It is used to store the symbol for the entry table.
*/

class SymbolTable{
    public:
        ~SymbolTable();
        static SymbolTable* getSymbolTable();
        int addToSymbolTable(std::string symbol, TableEntry entry);
        TableEntry getTableEntry(std::string symbol); 
        int getSymbolTableLocation(std::string symbol);
        int getSymbolTableLength();
        // push and pop scope if enter or exit a subroutine
        void addNewScope(); 
        void popScope();
        void popVariablesScope();
    private:
        static SymbolTable* uniqueSymbol;
        static std::vector<std::map<std::string, TableEntry>> symbolMaps;
        static int totalLength;
        SymbolTable();
        // we check if the symbol is duplicate under the same scope
        int checkSymbolDuplicate(std::string symbol);
        // scopes is the stack for keeping track of the subroutines
        static int scopes;
}; 

#endif 
