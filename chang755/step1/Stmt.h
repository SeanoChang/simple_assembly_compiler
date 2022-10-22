#ifndef STMT_H
#define STMT_H

#include <string>
#include <iostream>

class Stmt{
    public:
        virtual void getOpcode() = 0;
    private: 
        static const int opcode;
};

#endif 
