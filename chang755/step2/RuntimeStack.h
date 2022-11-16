#ifndef RUNTIME_STACK_H
#define RUNTIME_STACK_H

#include <vector>

class RuntimeStack {
    public: 
        RuntimeStack() {};
        ~RuntimeStack() {};
        void push(int val); /* push the value up to runtime stack */
        int pop(); /* pop the value off the runtime stack  */
        int peek(); /* peek at the top of the runtime stack */
    private:
        std::vector<int> runStack;
};

#endif 
