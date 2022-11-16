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
        std::string getInstruction(int loc); /* get the instruction at the location */
        int getState(int loc); /* get the state of the instruction at the location */
        static std::vector<std::unique_ptr<Instruction<Stmt>>> instMemory; /* instruction buffer with smart pointers  */
    private: 
        static int pc; /* program counter */
};

#endif 
