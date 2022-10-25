/* 
The class for constructing the instruction table structure.
Basically, it is the stack to store the op instructions.
*/
#include <iostream>
#include <memory>

#include "InstructionBuffer.h"

InstructionBuffer* InstructionBuffer::uniqueInst = NULL;
std::vector<std::unique_ptr<Instruction<Stmt>>> InstructionBuffer::instBuffer = std::vector<std::unique_ptr<Instruction<Stmt>>>();

InstructionBuffer::InstructionBuffer() {
    instBuffer.reserve(20);
}

InstructionBuffer* InstructionBuffer::getInstructionBuffer() {
    if (uniqueInst == NULL) {
        uniqueInst = new InstructionBuffer();
    }
    return uniqueInst;
}

void InstructionBuffer::addToInstructionBuffer(Stmt* stmt){
    if(stmt->getOpcode() != 0) instBuffer.push_back(make_unique<Instruction<Stmt>>(stmt));
}

void InstructionBuffer::printInstructionBuffer(){
    for (auto& inst : instBuffer) {
        std::cout << inst->getInstruction() << std::endl;
    }
}
