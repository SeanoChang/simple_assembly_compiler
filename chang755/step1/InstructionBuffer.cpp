/* 
The class for constructing the instruction table structure.
Basically, it is the stack to store the op instructions.
*/
#include <iostream>

#include "InstructionBuffer.h"

InstructionBuffer::InstructionBuffer() {
    this->instruction = 0;
    this->next = NULL;
}

InstructionBuffer::~InstructionBuffer() {
    delete this;
}


