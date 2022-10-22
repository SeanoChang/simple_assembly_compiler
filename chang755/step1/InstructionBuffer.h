#ifndef INSTRUCTIONBUFFER_H
#define INSTRUCTIONBUFFER_H

#include <iostream>

/*
We implement the instruction buffer with array of stmt pointers

This class is a singleton.
*/
class InstructionBuffer {
    public:
        ~InstructionBuffer();
    private: 
        // we need to the store the instruction with an array of smart unique pointers 
        long instruction;
        InstructionBuffer();
};

#endif
