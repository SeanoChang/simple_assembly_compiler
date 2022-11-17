#ifndef STRING_TABLE_H
#define STRING_TABLE_H

#include <vector>
#include <iostream>

class StringTable {
    public: 
        StringTable();
        ~StringTable() {};
        int addString(std::string str); /* add the string to string table */
        std::string getString(int loc); /* pop off the string from the string table  */

    private: 
        static std::vector<std::string> strTab;
};  

#endif 
