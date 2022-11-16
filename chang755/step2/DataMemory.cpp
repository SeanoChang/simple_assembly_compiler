/*
Data Memory class
Description: This class is for storing the variables and their value.
*/

#include <iostream>
#include "DataMemory.h"

DataMemory::DataMemory() {
    dataMem = std::vector<std::vector<int>>();
    dataMem.reserve(5);
    dataMem.push_back(std::vector<int>());
    scope = 0;
}

void DataMemory::push(int val) {
    dataMem[scope].push_back(val);
}

void DataMemory::setDataAtLocation(int loc, int val) {
    dataMem[scope][loc] = val;
}

void DataMemory::addNewScope() {
    if(dataMem.size() == dataMem.capacity()){
        dataMem.reserve(dataMem.capacity() * 2);
    }
    dataMem.push_back(std::vector<int>());
    scope++;
}

void DataMemory::popScope() {
    dataMem.pop_back();
}

int DataMemory::getDataAtLocation(int loc) {
    return dataMem[scope][loc];
}

int DataMemory::peek() {
    return dataMem[scope].back();
}

int DataMemory::pop() {
    int val = dataMem[scope].back();
    dataMem[scope].pop_back();
    return val;
}

