#ifndef HELPERS_H_
#define HELPERS_H_

#include <iostream>
#include "TableEntry.h"
#include "SymbolTable.h"
#include "StringBuffer.h"

int addToSymbolTable(std::string symbol, SymbolTable* symtab);
int addToStringBuffer(std::string symbol, StringBuffer* strbfr);
int addArrayToBuffer(std::string symbol, std::string length, SymbolTable* symtab);

#endif /* HELPERS_H_ */
