#ifndef INSTRUCTION_MEMORY_H
#define INSTRUCTION_MEMORY_H

#include <vector>

#include "Instruction.h"
class InstructionMemory {
    public:
        static InstructionMemory* getInstructionBuffer();
        void initializeInstMemory();
        ~InstructionMemory() {};
        void addToInstructionBuffer(Stmt* stmt, int loc, std::string);
        int getInstructionBufferSize() const;
        void printInstructionBuffer() const;
        static std::vector<std::unique_ptr<Instruction<Stmt>>> instBuffer;
    private: 
        // we need to the store the instruction with an array of smart unique pointers 
        static InstructionMemory* uniqueInst;
        InstructionMemory();
};

#endif 
