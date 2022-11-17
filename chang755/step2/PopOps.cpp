#include <iostream>

#include "PopOps.h"

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

/* op pop */
const int Oppop::opcode = OP_POP;
const std::string Oppop::operation= "Pop";

int Oppop::getOpcode(){
    return opcode;  
}

std::string Oppop::getOperation(){
    return operation;
}
