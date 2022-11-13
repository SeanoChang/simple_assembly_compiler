#include <iostream>

#include "DeclscalStmtOps.h"

/* Opdeclscalar */
const int Opdeclscalar::opcode = 0;
const std::string Opdeclscalar::operation= "DeclScalar";

int Opdeclscalar::getOpcode(){
    return opcode;  
}

std::string Opdeclscalar::getOperation(){
    return operation;
}