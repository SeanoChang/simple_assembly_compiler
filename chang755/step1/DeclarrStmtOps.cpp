#include <iostream>

#include "DeclarrStmtOps.h"

/* Opdeclarray */ 
const int Opdeclarray::opcode = 0;
const std::string Opdeclarray::operation= "DeclArray";

int Opdeclarray::getOpcode(){
    return opcode;  
}

std::string Opdeclarray::getOperation(){
    return operation;
}