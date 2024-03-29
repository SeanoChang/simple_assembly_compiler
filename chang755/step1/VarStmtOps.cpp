#include <iostream>

#include "VarStmtOps.h"

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

/* op popscalar */
const int Oppopscalar::opcode = OP_POPSCALAR;
const std::string Oppopscalar::operation= "PopScalar";

int Oppopscalar::getOpcode(){
    return opcode;  
}

std::string Oppopscalar::getOperation(){
    return operation;
}

/* op poparray */
const int Oppoparray::opcode = OP_POPARRAY;
const std::string Oppoparray::operation= "PopArray";

int Oppoparray::getOpcode(){
    return opcode;  
}

std::string Oppoparray::getOperation(){
    return operation;
}