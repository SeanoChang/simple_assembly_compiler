#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <string>

/*
Instruction class is a template for the instructions that make up the buffer.
Also, the instruction class is a stack.
*/

template <typename T> class Instruction{
    public: 
        Instruction ();
        Instruction (T* newInstruction);
        ~Instruction ();
    private: 
        T* instruction;
};

template <typename T> Instruction<T>::Instruction(){
    instruction = NULL;
}

template <typename T> Instruction<T>::Instruction(T* newInstruction){
    instruction = newInstruction;
}

template <typename T> Instruction<T>::~Instruction(){
    delete instruction;
}


#endif 
