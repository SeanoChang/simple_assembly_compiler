#include <iostream>

#include "StmtOps.h"

/* op return */
const int Opreturn::opcode = OP_RETURN;
const std::string Opreturn::operation= "Return";

int Opreturn::getOpcode(){
    return opcode;  
}

std::string Opreturn::getOperation(){
    return operation;
}

/* op start_program */
const int Opstartprogram::opcode = OP_START_PROGRAM;
const std::string Opstartprogram::operation= "Start";

int Opstartprogram::getOpcode(){
    return opcode;  
}

std::string Opstartprogram::getOperation(){
    return operation;
}

/* op exit_program */
const int Opexitprogram::opcode = OP_EXIT_PROGRAM;
const std::string Opexitprogram::operation= "Exit";

int Opexitprogram::getOpcode(){
    return opcode;  
}

std::string Opexitprogram::getOperation(){
    return operation;
}

/* op end program */
const int Opendprogram::opcode = 0;
const std::string Opendprogram::operation= "End";

int Opendprogram::getOpcode(){
    return opcode;  
}

std::string Opendprogram::getOperation(){
    return operation;
}