#include <iostream>

#include "GoSubOps.h"

/* op gosub */
const int Opgosub::opcode = OP_GOSUB;
const std::string Opgosub::operation= "GoSub";

int Opgosub::getOpcode(){
    return opcode;  
}

std::string Opgosub::getOperation(){
    return operation;
}

/* op gosublabel */
const int Opgosublabel::opcode = OP_ENTER_SUBROUTINE;
const std::string Opgosublabel::operation= "GoSubLabel";

int Opgosublabel::getOpcode(){
    return opcode;  
}

std::string Opgosublabel::getOperation(){
    return operation;
}
