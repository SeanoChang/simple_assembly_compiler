#ifndef DECLSCAL_STMT_OPS_H_
#define DECLSCAL_STMT_OPS_H_

#include "Stmt.h"

class Opdeclarray: public Stmt{   
    public: 
        Opdeclarray() {};
        ~Opdeclarray() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

#endif
