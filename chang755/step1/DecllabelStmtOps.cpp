#include <iostream>

#include "DecllabelStmtOps.h"

/* Oplabel */
const int Oplabel::opcode = 0;
const std::string Oplabel::operation= "Label";

int Oplabel::getOpcode(){
    return opcode;  
}

std::string Oplabel::getOperation(){
    return operation;
}

/* Opgosublabel */
const int Opgosublabel::opcode = OP_ENTER_SUBROUTINE;
const std::string Opgosublabel::operation= "GoSubLabel";

int Opgosublabel::getOpcode(){
    return opcode;  
}

std::string Opgosublabel::getOperation(){
    return operation;
}
