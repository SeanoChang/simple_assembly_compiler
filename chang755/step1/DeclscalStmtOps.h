#ifndef DECLARR_STMT_OPS_H_
#define DECLARR_STMT_OPS_H_

#include "Stmt.h"

class Opdeclscalar: public Stmt{   
    public: 
        Opdeclscalar() {};
        ~Opdeclscalar() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

#endif