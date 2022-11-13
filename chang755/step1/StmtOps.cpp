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

/* op pop */
const int Oppop::opcode = OP_POP;
const std::string Oppop::operation= "Pop";


int Oppop::getOpcode(){
    return opcode;  
}

std::string Oppop::getOperation(){
    return operation;
}

/* op dup */
const int Opdup::opcode = OP_DUP;
const std::string Opdup::operation= "Dup";

int Opdup::getOpcode(){
    return opcode;  
}

std::string Opdup::getOperation(){
    return operation;
}

/* op swap */
const int Opswap::opcode = OP_SWAP;
const std::string Opswap::operation= "Swap";

int Opswap::getOpcode(){
    return opcode;  
}

std::string Opswap::getOperation(){
    return operation;
}

/* op add */
const int Opadd::opcode = OP_ADD;
const std::string Opadd::operation= "Add";


int Opadd::getOpcode(){
    return opcode;  
}

std::string Opadd::getOperation(){
    return operation;
}

/* op negate */
const int Opnegate::opcode = OP_NEGATE;
const std::string Opnegate::operation= "Negate";


int Opnegate::getOpcode(){
    return opcode;  
}

std::string Opnegate::getOperation(){
    return operation;
}

/* op mul */
const int Opmul::opcode = OP_MUL;
const std::string Opmul::operation= "Mul";

int Opmul::getOpcode(){
    return opcode;  
}

std::string Opmul::getOperation(){
    return operation;
}

/* op div */
const int Opdiv::opcode = OP_DIV;
const std::string Opdiv::operation= "Div";

int Opdiv::getOpcode(){
    return opcode;  
}

std::string Opdiv::getOperation(){
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