#include <iostream>
#include <fstream>
#include <string>

#include "ReadWriteFile.h"

/*
This file will be handling the file i/o.
*/

// Read the instructions from the file and store them in the instruction memory.
// First, for cases that have print statements, we will need to read the strings from the file first,
// and store them in the string table.
// Then, we read the instructions and check if the instructions is valid.
// Only if the instruction is valid that we will store it in the memory.
// Otherwise we return null.



// Write output
// For print statements, we fetch the string from the string table and print it out.
// For printos statements, we pop the value from the runtime stack and print it out.