#ifndef INSTRUCTION_MEMORY_H
#define INSTRUCTION_MEMORY_H

#include <vector>

#include "Stmt.h"
#include "Instructions.h"
class InstructionMemory { 
    public:
        InstructionMemory();
        ~InstructionMemory() {};
        void addToInstructionMemory(Stmt* stmt, int loc); /* add instructions to the memory */
        std::string getInstruction(int loc); /* get the instruction at the location */
        int getState(int loc); /* get the state of the instruction at the location */
        int getSize(); /* get the size of the instruction memory */
        static std::vector<std::unique_ptr<Instruction<Stmt>>> instMemory; /* instruction buffer with smart pointers  */
    private: 
        static int pc; /* program counter */
};

#endif 
