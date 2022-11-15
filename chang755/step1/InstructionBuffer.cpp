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

void InstructionBuffer::addToInstructionBuffer(Stmt* stmt, int loc, std::string label) {
    if(stmt->getOpcode() != 0) {
        if(instBuffer.size() == instBuffer.capacity()){
            instBuffer.reserve(instBuffer.capacity() * 2);
        }
        instBuffer.push_back(Make_unique<Instruction<Stmt>>(stmt, loc, label));
    }
}

int InstructionBuffer::getInstructionBufferSize() const {
    return instBuffer.size();
}

void InstructionBuffer::printInstructionBuffer() const {
    for (auto& inst: instBuffer) {
        if(inst->getInstructionState() >= 0){
            if(inst->getInstruction() == "Prints"){
                std::cout << inst->getInstruction() << " " << inst->getLabel() << std::endl;
            } else if(inst->getInstruction() == "PrintTOS" || inst->getInstruction() == "Add" || inst->getInstruction() == "Div" || 
            inst->getInstruction() == "Return" || inst->getInstruction() == "Exit" || inst->getInstruction() == "Dup" || 
            inst->getInstruction() == "Swap" || inst->getInstruction() == "Pop" ||
            inst->getInstruction() == "Mul" || inst->getInstruction() == "Negate") {
                std::cout << inst->getInstruction() << " " << std::endl;
            } else{
                std::cout << inst->getInstruction() << " " << inst->getInstructionState() <<std::endl;
            }
        }
    }
}
