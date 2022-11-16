#ifndef POP_OPS_H
#define POP_OPS_H

#include "Stmt.h"

class Oppopscalar: public Stmt{   
    public: 
        Oppopscalar() {};
        ~Oppopscalar() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Oppoparray: public Stmt{   
    public: 
        Oppoparray() {};
        ~Oppoparray() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Oppop: public Stmt{   
    public: 
        Oppop() {};
        ~Oppop() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

#endif