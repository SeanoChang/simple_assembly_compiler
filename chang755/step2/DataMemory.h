#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H

#include <vector>

class DataMemory {
    public: 
        DataMemory();
        ~DataMemory(){};
        void push(int val); /* push on the data memory stack */
        void setDataAtLocation(int loc, int val); /* set the data at the location */
        void addNewScope(); /* add a new scope to the data memory */
        void popScope(); /* pop off the data memory stack */
        int getDataAtLocation(int loc); /* get the data at the location */
        int pop(); /* pop off the data from the stack */
        int peek(); /* peek at the top of the stack */
    private: 
        std::vector<std::vector<int>> dataMem;
        std::vector<int> scopeLengths;
        int totalLength;
        int scope;
};

#endif 
