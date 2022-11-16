#include <iostream>

#include "PrintsOps.h"

/* op prints */
const int Opprints::opcode = OP_PRINTS;
const std::string Opprints::operation= "Prints";

int Opprints::getOpcode(){
    return opcode;  
}

std::string Opprints::getOperation(){
    return operation;
}

/* op printtos */
const int Opprinttos::opcode = OP_PRINTTOS;
const std::string Opprinttos::operation= "PrintTOS";

int Opprinttos::getOpcode(){
    return opcode;  
}

std::string Opprinttos::getOperation(){
    return operation;
}