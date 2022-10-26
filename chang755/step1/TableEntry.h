#ifndef TABLEENTRY_H
#define TABLEENTRY_H
#include <string>
#include <iostream>

/* 
The table entry class is used to store the symbol with <location, legnth> pair.
The table entry is implement as a stack. 
use to push to add new entry and pop to remove the entry.
*/
class TableEntry{
    public:
        TableEntry();
        TableEntry(long location, long length);
        ~TableEntry() {};
        int getLocation() const;
        int getLength() const;
    private:
        std::string symbol;
        long location;
        long length;
};

#endif
