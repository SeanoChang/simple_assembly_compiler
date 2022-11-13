#ifndef PRINT_STMT_OPS_H_
#define PRINT_STMT_OPS_H_

#include "Stmt.h"

class Opprints: public Stmt{   
    public: 
        Opprints() {};
        ~Opprints() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opprinttos: public Stmt{   
    public: 
        Opprinttos() {};
        ~Opprinttos() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

#endif
