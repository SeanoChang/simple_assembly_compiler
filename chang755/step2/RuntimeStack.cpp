/*
Runtime Stack class
Description: This class is used to store the runtime stack for the program.
When something is popped off the data memory, it is stored in the runtime stack.
When something is pushed onto the data memory, it is taken from the runtime stack.
PushI push an integer onto the runtime stack.
*/

#include <iostream>
#include "RuntimeStack.h"

RuntimeStack::RuntimeStack() {
    runStack = std::vector<int>();
    runStack.reserve(5);
}

void RuntimeStack::push(int val) {
    if(runStack.size() == runStack.capacity()){
        runStack.reserve(runStack.capacity() * 2);
    }
    runStack.push_back(val);
}

int RuntimeStack::peek() {
    return runStack.back();
}

int RuntimeStack::pop() {
    int val = runStack.back();
    runStack.pop_back();
    return val;
}
