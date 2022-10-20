#ifndef INSTRUCTIONBUFFER_H
#define INSTRUCTIONBUFFER_H

#include <iostream>

class InstructionBuffer {
    public:
        InstructionBuffer();
        ~InstructionBuffer();
    private: 
        long instruction;
        InstructionBuffer* next;
};

#endif
