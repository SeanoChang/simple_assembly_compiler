#ifndef GO_SUB_OPS_H_
#define GO_SUB_OPS_H_

#include "Stmt.h"

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

#endif 
