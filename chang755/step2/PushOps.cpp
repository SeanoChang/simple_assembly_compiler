#include <iostream>

#include "PushOps.h"

/* op pushscalar */
const int Oppushscalar::opcode = OP_PUSHSCALAR;
const std::string Oppushscalar::operation= "PushScalar";

int Oppushscalar::getOpcode(){
    return opcode;  
}

std::string Oppushscalar::getOperation(){
    return operation;
}

/* op pusharray */
const int Oppusharray::opcode = OP_PUSHARRAY;
const std::string Oppusharray::operation= "PushArray";

int Oppusharray::getOpcode(){
    return opcode;  
}

std::string Oppusharray::getOperation(){
    return operation;
}

/* op pushi */
const int Oppushi::opcode = OP_PUSHI;
const std::string Oppushi::operation= "PushI";

int Oppushi::getOpcode(){
    return opcode;  
}

std::string Oppushi::getOperation(){
    return operation;
}