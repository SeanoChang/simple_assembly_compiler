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
    scopeLengths = std::vector<int>();
    scopeLengths.reserve(5);

    scope = 0;
}

void DataMemory::push(int val) {
    dataMem[scope].push_back(val);
    scopeLengths[scope]++;
    totalLength++;
}

void DataMemory::setDataAtLocation(int loc, int val) {
    int location = loc;
    if(scope > 0){
        for(int i = scope; i > 0; i--){
            location -= scopeLengths[i-1];
        }
    }
    dataMem[scope][location] = val;
}

void DataMemory::addNewScope() {
    if(dataMem.size() == dataMem.capacity()){
        dataMem.reserve(dataMem.capacity() * 2);
    }
    dataMem.push_back(std::vector<int>());
    scopeLengths.push_back(0);
    scope++;
}

void DataMemory::popScope() {
    dataMem.pop_back();
    totalLength -= scopeLengths[scope];
    scope--;
}

int DataMemory::getDataAtLocation(int loc) {
    int location = loc;
    if(scope > 0){
        for(int i = scope; i-1 > 0; i--){
            location -= scopeLengths[i-1];
        }
    }
    return dataMem[scope][location];
}

int DataMemory::peek() {
    return dataMem[scope].back();
}

int DataMemory::pop() {
    int val = dataMem[scope].back();
    dataMem[scope].pop_back();
    return val;
}

