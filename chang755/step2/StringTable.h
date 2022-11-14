#ifndef STRING_TABLE_H
#define STRING_TABLE_H

#include <vector>
#include <iostream>

class StringTable {
    public: 
        StringTable();
        ~StringTable();
        int addString(char* str);
        std::string getString(int index);

    private: 
        std::vector<std::string> strTab;
};  

#endif 
