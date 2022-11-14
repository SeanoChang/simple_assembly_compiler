#ifndef RUNTIME_STACK_H
#define RUNTIME_STACK_H

#include <vector>

class RuntimeStack {
    public: 
        RuntimeStack();
        ~RuntimeStack();
        int push(int val);
        int pop();
    private:
        std::vector<int> runStack;
};

#endif 
