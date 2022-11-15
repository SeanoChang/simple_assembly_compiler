/*
Data Memory class
Description: This class is for storing the variables and their value.
*/

#include <iostream>
#include "DataMemory.h"

DataMemory::DataMemory() {
    this->dataMem.push_back(0);
}

int DataMemory::push(int val) {
    dataMem.push_back(val);
}

int DataMemory::pop() {
    dataMem.pop_back();
}

