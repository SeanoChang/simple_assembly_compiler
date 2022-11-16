#ifndef INSTRUCTIONBUFFER_H
#define INSTRUCTIONBUFFER_H

#include <iostream>
#include <vector>

#include "Instruction.h"
#include "Stmt.h"
#include "StringBuffer.h"
#include "TableEntry.h"
#include "SymbolTable.h"

/*
We implement the instruction buffer with array of stmt pointers

This class is a singleton.
*/
class InstructionBuffer: public Instruction<Stmt*> {
    public:
        static InstructionBuffer* getInstructionBuffer();
        void initializeInstBuffer();
        ~InstructionBuffer() {};
        void addToInstructionBuffer(Stmt* stmt, int loc, std::string);
        int getInstructionBufferSize() const;
        void printInstructionBuffer() const;
        static std::vector<std::unique_ptr<Instruction<Stmt>>> instBuffer;
        void patchUpInstructionBuffer(SymbolTable* symtab, int goSubLabel);
    private: 
        // we need to the store the instruction with an array of smart unique pointers 
        static InstructionBuffer* uniqueInst;
        InstructionBuffer();
};

#endif
