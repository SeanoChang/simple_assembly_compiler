/*
Virtual Machine class.
Description: This class will take the input from the file and store it in the instruction memory.
The input file first starts with the strings and then the instructions.
We first read in all the strings if needed and store them in the string table.
Then we read in the instructions and store them in the instruction memory.
*/

#include <iostream>
#include <fstream>
#include <string>

#include "VirtualMachine.h"

VirtualMachine::VirtualMachine(){
    instMem = new InstructionMemory();
    dataMem = new DataMemory();
    strTable = new StringTable();
    runStack = new RuntimeStack();
    std::map<int, std::string> results = std::map<int, std::string>();
}

VirtualMachine::~VirtualMachine(){
    delete instMem;
    delete dataMem;
    delete strTable;
    delete runStack;
}

int VirtualMachine::run(std::ifstream& infile, std::ofstream& outfile){
    /* step 1 read all the string and put them into the string buffer -- josh */
    std::ifstream myfile (argv[1]);
    std::string mystring;

    if ( myfile.is_open() )  //https://www.udacity.com/blog/2021/05/how-to-read-from-a-file-in-cpp.html
    {     
        while ( myfile.good() ) //read a string til it breaks; automatically ends when there's no more
        {
        myfile >> mystring;
        StringBuffer::addString(mystring); //include StringBuffer.h?
        }          
    }


    /* step2 read the instructions and add to the instruction memory 1 by 1, then do the instructions -- sean  
        result will be store in an map with the key is the order to print */

    /* step3 write the result to the output file -- josh */

    

    return 0;
}