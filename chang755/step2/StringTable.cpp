/*
String Table class.
Description: This class will store all the strings that are read in from the input file.
This class will be implemented as a singleton.
*/

#include <iostream>
#include "StringTable.h"

StringTable::StringTable() {
    this->strTab.push_back(0);
    vec_idx = 0;
}

std::string StringTable::getStringTable(int index) {
    return(strTab.pop_back(index))
}

int StringTable::addString(char* str, int vec_idx) {
    strTab[vec_idx].push_back(str);
    vec_idx ++;
    return 1;
}

