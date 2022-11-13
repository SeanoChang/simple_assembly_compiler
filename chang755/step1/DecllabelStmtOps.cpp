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

/* op exit_subroutine */
const int Opexitsubroutine::opcode = OP_EXIT_SUBROUTINE;
const std::string Opexitsubroutine::operation= "ExitSubroutine";

int Opexitsubroutine::getOpcode(){
    return opcode;  
}

std::string Opexitsubroutine::getOperation(){
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
