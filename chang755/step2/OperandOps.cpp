#include <iostream>

#include "OperandOps.h"

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
