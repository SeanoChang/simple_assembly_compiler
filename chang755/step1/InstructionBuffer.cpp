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

void InstructionBuffer::patchUpInstructionBuffer(SymbolTable* symtab) {
    for(auto& inst : instBuffer) {
        std::string str = inst->getInstruction();
        if(inst->getInstructionState() == -2){ // if the instruction has empty state then patch up
            if(str == "Start"){ // patching start with size of symtab
                inst->setInstructionState(symtab->getSymbolTableLength());
            } else if(str == "GoSub" || str == "Jump"){ // patching GoSub with the label and location of the label 
                inst->setInstructionState(symtab->getSymbolTableLocation(inst->getLabel()));
            } else if(str == "Mul" || str == "Div" || str == "Add" || str == "Dup" ||
             str == "Swap" || str == "Pop" || str == "Push" || str == "PrintTOS" || str == "Return"
             || str == "Exit" || str == "Negate") {
                inst->setInstructionState(0);
            }
        }
    }
}

void InstructionBuffer::printInstructionBuffer() const {
    for (auto& inst: instBuffer) {
        std::string str = inst->getInstruction();
        if(inst->getInstructionState() >= 0){
            if(str == "Prints"){
                std::cout << str << " " << inst->getLabel() << std::endl;
            } else if(str == "PrintTOS" || str == "Add" || str == "Div" || 
            str == "Return" || str == "Exit" || str == "Dup" || 
            str == "Swap" || str == "Pop" ||
            str == "Mul" || str == "Negate") {
                std::cout << str << " " << std::endl;
            } else if(str == "GoSub" || str == "PopScalar" || str == "PushScalar" ||
            str == "PushArray" || str == "PopArray" || str == "JumpZero" ||
            str == "JumpNZero") {
                std::cout << str << " " << inst->getLabel() << " " << inst->getInstructionState()  << std::endl;
            } else if(str == "GoSubLabel"){
                std::cout << str << " " << inst->getLabel() << std::endl;
            } else{
                std::cout << str << " " << inst->getInstructionState() <<std::endl;
            }
        }
    }
}
