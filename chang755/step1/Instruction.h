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
        std::string getInstruction();
    private: 
        T* instruction;
        int state;
};

template <typename T> Instruction<T>::Instruction(){
    instruction = NULL;
    state = -1;
};

template <typename T> Instruction<T>::Instruction(T* newInstruction){
    instruction = newInstruction;
};

template <typename T> Instruction<T>::~Instruction(){
    delete instruction;
};

template <typename T> std::string Instruction<T>::getInstruction(){
    return instruction->getOperation();
};

// the part for make unique
template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
};

#endif 
