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
