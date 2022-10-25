#ifndef INSTRUCTIONBUFFER_H
#define INSTRUCTIONBUFFER_H

#include <iostream>
#include <vector>

#include "Instruction.h"
#include "Stmt.h"

/*
We implement the instruction buffer with array of stmt pointers

This class is a singleton.
*/
class InstructionBuffer: public Instruction<Stmt*> {
    public:
        static InstructionBuffer* getInstructionBuffer();
        static std::vector<std::unique_ptr<Instruction<Stmt*>>> instBuffer;
        ~InstructionBuffer() {};
        void addToInstructionBuffer(Stmt* stmt);
        void addToInstructionBuffer(Stmt* stmt, std::string var);
        void addToInstructionBuffer(Stmt* stmt, std::string var1, std::string var2);
    private: 
        // we need to the store the instruction with an array of smart unique pointers 
        static InstructionBuffer* uniqueInst;
        InstructionBuffer() {};
};

#endif
