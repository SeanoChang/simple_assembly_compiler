/*
Virtual Machine class.
Description: This class will take the input from the file and store it in the instruction memory.
The input file first starts with the strings and then the instructions.
We first read in all the strings if needed and store them in the string table.
Then we read in the instructions and store them in the instruction memory.
*/

#include <iostream>

#include "VirtualMachine.h"

VirtualMachine::VirtualMachine(){
    instMem = new InstructionMemory();
    dataMem = new DataMemory();
    strTable = new StringTable();
    runStack = new RuntimeStack();
}