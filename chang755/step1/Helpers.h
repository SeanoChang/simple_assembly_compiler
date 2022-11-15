#ifndef HELPERS_H_
#define HELPERS_H_

#include <iostream>
#include "TableEntry.h"
#include "SymbolTable.h"
#include "StringBuffer.h"

int addScalarToSymbolTable(std::string symbol, SymbolTable* symtab);
int addLabelToSymbolTable(std::string symbol, int location, SymbolTable* symtab);
int addToStringBuffer(std::string symbol, StringBuffer* strbfr);
int addArrayToBuffer(std::string symbol, std::string length, SymbolTable* symtab);

#endif /* HELPERS_H_ */
