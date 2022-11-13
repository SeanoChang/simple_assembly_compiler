#ifndef HELPERS_H_
#define HELPERS_H_

#include <iostream>
#include "TableEntry.h"
#include "SymbolTable.h"
#include "StringBuffer.h"

int print_ops_addToBuffer(std::string str, StringBuffer* strBuffer);

int var_stmt_ops_addToBuffer(std::string var, SymbolTable* sTable);

int int_stmt_ops_addToBuffer(std::string var);

int declscal_stmt_ops_addToBuffer(std::string symbol, SymbolTable* sTable);

int declarr_stmt_ops_addToBuffer(std::string var1, std::string var2, SymbolTable* sTable);

int decllabel_stmt_ops_addToBuffer(std::string symbol, SymbolTable* sTable);

int label_stmt_ops_addToBuffer(std::string symbol, SymbolTable* sTable);

#endif /* HELPERS_H_ */
