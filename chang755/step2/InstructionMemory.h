#ifndef INSTRUCTION_MEMORY_H
#define INSTRUCTION_MEMORY_H

#include <vector>

#include "Stmt.h"
#include "Instruction.h"
class InstructionMemory { 
    public:
        InstructionMemory();
        ~InstructionMemory() {};
        int addToInstructionMemory(Stmt* stmt, int loc, std::string); /* add instructions to the memory */
        static std::vector<std::unique_ptr<Instruction<Stmt>>> instMemory; /* instruction buffer with smart pointers  */
};

#endif 
