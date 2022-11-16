#include <iostream>

#include "GoSubOps.h"

class Opgosub: public Stmt{   
    public: 
        Opgosub() {};
        ~Opgosub() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

