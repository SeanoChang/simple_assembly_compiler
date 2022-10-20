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
        ~TableEntry();
        void deleteTableEntry();
        void push(std::string symbol, int location, int length);
        void pop();
    private:
        std::string symbol;
        long location;
        long length;
        TableEntry* next;
        // TableEntry* top;
};

#endif
