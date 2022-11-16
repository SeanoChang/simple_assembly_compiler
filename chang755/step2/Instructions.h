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
        Instruction (T* newInstruction, int loc);
        ~Instruction ();
        std::string getInstruction();
        int getInstructionState();
        void setInstructionState(int _state);
        T* getInstructionPtr();
    private: 
        T* instruction;
        int state;
};

template <typename T> Instruction<T>::Instruction(){
    instruction = NULL;
    state = -1;
};

template <typename T> Instruction<T>::Instruction(T* newInstruction, int loc){
    instruction = newInstruction;
    state = loc;
};

template <typename T> Instruction<T>::~Instruction(){
    delete instruction;
};

template <typename T> std::string Instruction<T>::getInstruction(){
    return instruction->getOperation();
};

template <typename T> int Instruction<T>::getInstructionState(){
    return state;
};

template <typename T> void Instruction<T>::setInstructionState(int _state){
    state = _state;
};

template <typename T> T* Instruction<T>::getInstructionPtr(){
    return instruction;
};

// the part for make unique
template <typename T, typename... Args> std::unique_ptr<T> Make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
};

#endif 
