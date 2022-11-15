/*
String Table class.
Description: This class will store all the strings that are read in from the input file.
This class will be implemented as a singleton.
*/

#include <iostream>
#include "StringTable.h"

std::vector<std::string> StringTable::strTab = std::vector<std::string>();

StringTable::StringTable() {
    strTab.reserve(20);
}

std::string StringTable::getString() {
    std::string str = strTab[strTab.size()-1];
    strTab.pop_back();
    return str;
}

int StringTable::addString(std::string str) {
    if(strTab.size() == strTab.capacity()){
        strTab.reserve(strTab.capacity() * 2);
    }
    strTab.push_back(str);
    return 1;
}

