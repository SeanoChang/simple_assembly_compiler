#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H

#include <vector>

class DataMemory {
    public: 
        DataMemory();
        ~DataMemory();
        int push(int val);
        int pop();
    private: 
        std::vector<int> dataMem;
};

#endif 
