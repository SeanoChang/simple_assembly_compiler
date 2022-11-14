#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H

#include "InstructionMemory.h"
#include "RuntimeStack.h"
#include "DataMemory.h"
#include "StringTable.h"

class VirtualMachine {
    public: 
        VirtualMachine();
        ~VirtualMachine();
        int run();
        int loadProgram();

    private: 
        int pc;
        InstructionMemory* instMem;
        DataMemory* dataMem;
        StringTable* strTable;
        RuntimeStack* runStack;
};

#endif 
