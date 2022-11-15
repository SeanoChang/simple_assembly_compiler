#ifndef STRING_TABLE_H
#define STRING_TABLE_H

#include <vector>
#include <iostream>

class StringTable {
    public: 
        StringTable();
        ~StringTable();
        int addString(char* str); /* add the string to string table */
        std::string getString(int index); /* pop off the string from the string table  */

    private: 
        std::vector<std::string> strTab;
        int vec_idx;
};  

#endif 
