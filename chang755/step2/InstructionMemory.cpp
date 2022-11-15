/*
Instruction Memory class
Description: This class is for storing the instructions and their location.
*/

#include <iostream>
#include "InstructionMemory.h"

InstructionMemory::InstructionMemory(){
    InstructionMemory.reserve(20);
}

InstructionMemory::~InstructionMemory() {
    delete instMemory;
}

int InstructionMemory::addToInstructionMemory(Stmt* stmt, int loc, std::string label) {
    if(stmt->getOpcode() != 0) {
        if(instMemory.size() == instMemory.capacity()){
            instMemory.reserve(instMemory.capacity() * 2);
        }
        instMemory.push_back(Make_unique<Instruction<Stmt>>(stmt, loc, label));
    }
}

std::vector<std::string> InstructionMemory::instMemory = std::vector<std::string>();

