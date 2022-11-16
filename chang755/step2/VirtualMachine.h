#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H

#include <iostream>
#include <fstream>
#include <map>

#include "InstructionMemory.h"
#include "RuntimeStack.h"
#include "DataMemory.h"
#include "StringTable.h"

class VirtualMachine {
    public: 
        VirtualMachine();
        ~VirtualMachine();
        int run(std::ifstream& infile, std::ofstream& outfile); /* run the virtual machine */
        std::map<int, std::string> results; /* result of the virtual machine */

    private: 
        InstructionMemory* instMem;
        DataMemory* dataMem;
        StringTable* strTable;
        RuntimeStack* runStack;
};

#endif 
