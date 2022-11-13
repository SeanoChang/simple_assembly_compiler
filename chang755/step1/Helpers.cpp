#include <iostream>
#include <string>
#include "Helpers.h"

/* return the location of the string store in the string buffer */
int print_ops_addToBuffer(std::string str, StringBuffer* strBuffer) {
    // add the string to the string buffer
    return strBuffer -> addString(str);
};

/* do not add the symbol table yet, if the var doesn't exist in symbol table
otherwise, return the location of the entry in sTable */
int var_stmt_ops_addToBuffer(std::string var, SymbolTable* sTable) {
    // check exitance of the var in the symbol table
    if (sTable -> symbolExist(var)) {
        // return the location of the entry in the symbol table
        return sTable -> getSymbolTableLocation(var);
    } else {
       return -1;
    } 
};

int int_stmt_ops_addToBuffer(std::string var) {
    // -> return the nubmer of the integer converted from string
    return std::stoi(var);
};


/* declare statements return the location(int) of the new entry in the symbol table */
int declscal_stmt_ops_addToBuffer(std::string symbol, SymbolTable* sTable) {
    // add the string to the symbol table
    int curLen = sTable -> getSymbolTableLength();
    return sTable->addToSymbolTable(symbol, TableEntry(curLen, 1));
};

int declarr_stmt_ops_addToBuffer(std::string var1, std::string var2, SymbolTable* sTable) {
    // add the string to the symbol table
    int curLen = sTable -> getSymbolTableLength();
    std::cout << var2  << std::endl;
    return sTable->addToSymbolTable(var1, TableEntry(curLen, std::stoi(var2)));
};


/* declare label */
int decllabel_stmt_ops_addToBuffer(std::string symbol, SymbolTable* sTable) {
    //add to the symbol table
    int curLen = sTable->getSymbolTableLength();
    return sTable -> addToSymbolTable(symbol, TableEntry(curLen, 0));
};


/* check in the symbol table whether the symbol is declared or not,
if declared return the location otherwise do nothing */
int label_stmt_ops_addToBuffer(std::string symbol, SymbolTable* sTable) {
    // add the string to the symbol table
    if(sTable->symbolExist(symbol)) {
        return sTable->getSymbolTableLocation(symbol);
    } else {
        return -1;
    }
};
