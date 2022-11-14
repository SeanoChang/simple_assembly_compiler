#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H

#include <vector>

class DataMemory {
    public: 
        DataMemory();
        ~DataMemory();
        int push(int val); /* push on the data memory stack */
        int pop(); /* pop off the data from the stack */
    private: 
        std::vector<int> dataMem;
};

#endif 
