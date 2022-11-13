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
#include "Parser.h"

int main(int argc, char* argv[]){
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

    std::ofstream outFile(infile+".out", std::ios::out | std::ios::binary);
    if(!outFile){
        std::cout << "Cannot open .out file" << std::endl;
        exit(1);
    }

    std::ofstream poutFile(infile+".pout", std::ios::out);
    if(!poutFile){
        std::cout << "Cannot open .pout file" << std::endl;
        exit(1);
    }

    Parser parser = Parser();
    if(parser.parse(inFile, outFile, poutFile) == -1){
        std::cerr << "Error in parsing" << std::endl;
        exit(1);
    }

    exit(0);
}
