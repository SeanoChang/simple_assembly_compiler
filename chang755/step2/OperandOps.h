#ifndef OPERAND_OPS_H
#define OPERAND_OPS_H

#include "Stmt.h"

class Opadd: public Stmt{   
    public: 
        Opadd() {};
        ~Opadd() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opnegate: public Stmt{   
    public: 
        Opnegate() {};
        ~Opnegate() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opmul: public Stmt{   
    public: 
        Opmul() {};
        ~Opmul() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opdiv: public Stmt
{   
    public: 
        Opdiv() {};
        ~Opdiv() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

#endif 
