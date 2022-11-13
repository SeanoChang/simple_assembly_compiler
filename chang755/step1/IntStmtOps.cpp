#include <iostream>

#include "IntStmtOps.h"

/* op pushi */
const int Oppushi::opcode = OP_PUSHI;
const std::string Oppushi::operation= "PushI";

int Oppushi::getOpcode(){
    return opcode;  
}

std::string Oppushi::getOperation(){
    return operation;
}