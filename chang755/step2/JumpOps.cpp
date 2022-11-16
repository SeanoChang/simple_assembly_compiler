#include <iostream>

#include "JumpOps.h"

const int Opjump::opcode = OP_JUMP;
const std::string Opjump::operation= "Jump";

int Opjump::getOpcode(){
    return opcode;  
}

std::string Opjump::getOperation(){
    return operation;
}


/* op jumpzero */
const int Opjumpzero::opcode = OP_JUMPZERO;
const std::string Opjumpzero::operation= "JumpZero";

int Opjumpzero::getOpcode(){
    return opcode;  
}

std::string Opjumpzero::getOperation(){
    return operation;
}

/* op jumpnzero */
const int Opjumpnzero::opcode = OP_JUMPNZERO;
const std::string Opjumpnzero::operation= "JumpNZero";

int Opjumpnzero::getOpcode(){
    return opcode;  
}

std::string Opjumpnzero::getOperation(){
    return operation;
}
