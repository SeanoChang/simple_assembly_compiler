/*
This is the main function for the step 1 part of the project.
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#include "StringBuffer.h"
#include "InstructionBuffer.h"
#include "TableEntry.h"
#include "SymbolTable.h"

int main(int argc, char* argv[]){
    std::cout<< argc << std::endl;
    std::ifstream inFile(argv[1], std::ios::in | std::ios::binary);
    if(!inFile){
        std::cout << "Cannot open input file" << std::endl;
        return exit(1);
    }

    std::ofstream outFile(argv[1]+".out", std::ios::out);
    if(!outFile){
        std::cout << "Cannot open .out file" << std::endl;
        return exit(1);
    }

    std::ofstream poutFile(argv[1]+".pout", std::ios::out | std::ios::binary);
    if(!poutFile){
        std::cout << "Cannot open .pout file" << std::endl;
        return exit(1);
    }

    Parser parser();
    parser.parse(inFile, outFile, poutFile);

    return exit(0);
}   