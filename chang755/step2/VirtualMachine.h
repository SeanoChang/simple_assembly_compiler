#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H

#include <iostream>
#include <fstream>
#include <string>

#include "Stmt.h"
#include "StmtOps.h"
#include "PushOps.h"
#include "PopOps.h"
#include "PrintsOps.h"
#include "OperandOps.h"
#include "JumpOps.h"
#include "DupSwap.h"
#include "GoSubOps.h"
#include "InstructionMemory.h"
#include "RuntimeStack.h"
#include "DataMemory.h"
#include "StringTable.h"

class VirtualMachine {
    public: 
        VirtualMachine();
        ~VirtualMachine();
        int run(std::ifstream& infile, std::ofstream& outfile); /* run the virtual machine */
        int readToBuffers(std::ifstream& infile); /* read the input file and put the lines into the buffers */
        void processInstructions(); /* process the instructions */
        void writeOutput(std::ofstream& outfile); /* write the output to the output file */
        Stmt* createInstruction(std::string op); /* create the instruction object */
        std::vector<std::string> results; /* result of the virtual machine */

    private: 
        InstructionMemory* instMem;
        DataMemory* dataMem;
        StringTable* strTable;
        RuntimeStack* runStack;
};

#endif 
