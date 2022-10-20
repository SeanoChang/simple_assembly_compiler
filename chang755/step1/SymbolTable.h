#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <string>
#include <iostream>
#include <map>

/*
The SymbolTable class is a singleton class.
It is used to store the symbol for the entry table.
*/
class SymbolTable{
    public:
        static SymbolTable* getSymbol(std::string);
        static void destroySymbol();
        int idx;
        std::map<std::string, long> definedMap();
    private:
        static SymbolTable* uniqueSymbol;
        std::string symbol;
        SymbolTable();
        SymbolTable(std::string);
        ~SymbolTable();
}; 

#endif 
