#include <iostream>

#include "DecllabelStmtOps.h"

/* op enter_subroutine */
const int Opentersubroutine::opcode = OP_ENTER_SUBROUTINE;
const std::string Opentersubroutine::operation= "EnterSubroutine";

Opentersubroutine::Opentersubroutine() {
    takeInputBehavior = new decllabel_stmt_ops();
}

int Opentersubroutine::getOpcode(){
    return opcode;  
}

std::string Opentersubroutine::getOperation(){
    return operation;
}

/* op exit_subroutine */
const int Opexitsubroutine::opcode = OP_EXIT_SUBROUTINE;
const std::string Opexitsubroutine::operation= "ExitSubroutine";

Opexitsubroutine::Opexitsubroutine() {
    takeInputBehavior = new decllabel_stmt_ops();
}

int Opexitsubroutine::getOpcode(){
    return opcode;  
}

std::string Opexitsubroutine::getOperation(){
    return operation;
}

/* Oplabel */
const int Oplabel::opcode = 0;
const std::string Oplabel::operation= "Label";

Oplabel::Oplabel(){
    takeInputBehavior = new decllabel_stmt_ops();
}

int Oplabel::getOpcode(){
    return opcode;  
}

std::string Oplabel::getOperation(){
    return operation;
}

/* Opgosublabel */
const int Opgosublabel::opcode = 0;
const std::string Opgosublabel::operation= "GoSubLabel";

Opgosublabel::Opgosublabel(){
    takeInputBehavior = new decllabel_stmt_ops();
}

int Opgosublabel::getOpcode(){
    return opcode;  
}

std::string Opgosublabel::getOperation(){
    return operation;
}
