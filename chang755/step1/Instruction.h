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
        Instruction (T* newInstruction, int loc, std::string);
        ~Instruction ();
        std::string getInstruction();
        std::string getLabel();
        int getInstructionState();
        void setInstructionState(int _state);
        void setLabel(std::string _label);
        T* getInstructionPtr();
    private: 
        T* instruction;
        int state;
        std::string label;
};

template <typename T> Instruction<T>::Instruction(){
    instruction = NULL;
    state = -1;
    label = "";
};

template <typename T> Instruction<T>::Instruction(T* newInstruction, int loc, std::string _label){
    instruction = newInstruction;
    state = loc;
    label = _label;
};

template <typename T> Instruction<T>::~Instruction(){
    delete instruction;
};

template <typename T> std::string Instruction<T>::getInstruction(){
    return instruction->getOperation();
};

template <typename T> std::string Instruction<T>::getLabel(){
    return label;
};

template <typename T> int Instruction<T>::getInstructionState(){
    return state;
};

template <typename T> void Instruction<T>::setInstructionState(int _state){
    state = _state;
};

template <typename T> void Instruction<T>::setLabel(std::string _label){
    label = _label;
};

template <typename T> T* Instruction<T>::getInstructionPtr(){
    return instruction;
};

// the part for make unique
template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
};

#endif 
