#ifndef INT_STMT_OPS_H_
#define INT_STMT_OPS_H_

#include "Stmt.h"

class Oppushi: public Stmt{   
    public: 
        Oppushi() {};
        ~Oppushi() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

#endif
