#include <iostream>

#include "DupSwap.h"

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
