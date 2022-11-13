#include <iostream>

#include "DecllabelStmtOps.h"

/* op enter_subroutine */
const int Opentersubroutine::opcode = OP_ENTER_SUBROUTINE;
const std::string Opentersubroutine::operation= "EnterSubroutine";

int Opentersubroutine::getOpcode(){
    return opcode;  
}

std::string Opentersubroutine::getOperation(){
    return operation;
}

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
const int Opgosublabel::opcode = 0;
const std::string Opgosublabel::operation= "GoSubLabel";

int Opgosublabel::getOpcode(){
    return opcode;  
}

std::string Opgosublabel::getOperation(){
    return operation;
}
