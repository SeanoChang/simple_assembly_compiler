#ifndef DECLLABEL_STMT_OPS_H
#define DECLLABEL_STMT_OPS_H

#include "Stmt.h"

class Opentersubroutine: public Stmt{   
    public: 
        Opentersubroutine() {};
        ~Opentersubroutine() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Oplabel: public Stmt{   
    public: 
        Oplabel() {};
        ~Oplabel() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opgosublabel: public Stmt{   
    public: 
        Opgosublabel() {};
        ~Opgosublabel() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

#endif
