#ifndef RUNTIME_STACK_H
#define RUNTIME_STACK_H

#include <vector>

class RuntimeStack {
    public: 
        RuntimeStack() {};
        ~RuntimeStack() {};
        int push(int val); /* push the value up to runtime stack */
        int pop(); /* pop the value off the runtime stack  */
    private:
        std::vector<int> runStack;
};

#endif 
