/*
Instruction Memory class
Description: This class is for storing the instructions and their location.
*/

#include <iostream>
#include "InstructionMemory.h"

std::vector<std::unique_ptr<Instruction<Stmt>>> InstructionMemory::instMemory = std::vector<std::unique_ptr<Instruction<Stmt>>>();

InstructionMemory::InstructionMemory(){
    instMemory.reserve(20);
}

std::string InstructionMemory::getInstruction(int loc) {
    return instMemory[loc]->getInstruction();
}

int InstructionMemory::getState(int loc) {
    return instMemory[loc]->getInstructionState();
}

int InstructionMemory::getSize() {
    return instMemory.size();
}

void InstructionMemory::addToInstructionMemory(Stmt* stmt, int loc) {
    if(stmt->getOpcode() != 0) {
        if(instMemory.size() == instMemory.capacity()){
            instMemory.reserve(instMemory.capacity() * 2);
        }
        instMemory.push_back(Make_unique<Instruction<Stmt>>(stmt, loc));
    }
}

