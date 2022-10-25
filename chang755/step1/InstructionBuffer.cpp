/* 
The class for constructing the instruction table structure.
Basically, it is the stack to store the op instructions.
*/
#include <iostream>

#include "InstructionBuffer.h"

InstructionBuffer* InstructionBuffer::uniqueInst = NULL;
std::vector<std::unique_ptr<Instruction<Stmt*>>> InstructionBuffer::instBuffer = std::vector<std::unique_ptr<Instruction<Stmt*>>>();

InstructionBuffer::InstructionBuffer() {
}

InstructionBuffer* InstructionBuffer::getInstructionBuffer() {
    if (uniqueInst == NULL) {
        uniqueInst = new InstructionBuffer();
    }
    return uniqueInst;
}

void addToInstructionBuffer(Stmt* stmt){
    if(instBuffer.size() == instBuffer.capacity()){ // if the buffer is full double the size
        instBuffer.reserve(instBuffer.capacity() * 2);
    }

    instBuffer.push_back(std::unique_ptr<Instruction<Stmt*>>(new Instruction<Stmt*>(stmt)));
}
void addToInstructionBuffer(Stmt* stmt, std::string var);
void addToInstructionBuffer(Stmt* stmt, std::string var1, std::string var2);
