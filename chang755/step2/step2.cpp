#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <regex>

#include "VirtualMachine.h"

/*
This is the main of step two.
For this step, we will be building the Virtual Machine.

*/

int main(int argc, char* argv[]) {
    // Read the instructions from the file
    // and store them in the instruction memory,
    // string table if needed.

    if(argc == 1){
        std::cout << "No input file" << std::endl;
        exit(1);
    }

    std::string infile = argv[1];
    std::ifstream inFile(infile, std::ios::in | std::ios::binary);
    if(!inFile){
        std::cout << "Cannot open input file" << std::endl;
        exit(1);
    }

    // std::ofstream outFile(infile+".out", std::ios::out);
    // if(!outFile){
    //     std::cout << "Cannot open .out file" << std::endl;
    //     exit(1);
    // }
    std::regex re("([0-9a-zA-Z_]+)/([0-9a-zA-Z_]+).([0-9a-zA-Z_]+)");
    std::smatch sm;
    std::regex_search(infile,sm,re);
    std::string voutfile = sm[2];

    std::ofstream voutFile(voutfile+".vout",  std::ios::out);
    if(!voutFile){
        std::cout << "Cannot open .pout file" << std::endl;
        exit(1);
    }
    
    VirtualMachine vm = VirtualMachine();
    if(vm.run(inFile, voutFile) == -1){
        std::cerr << "Error in running of the file is empty." << std::endl;
        exit(1);
    }

    inFile.close();
    voutFile.close();

    exit(0);


    // Execute the instructions in the instruction memory


}

