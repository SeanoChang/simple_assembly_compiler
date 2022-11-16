#ifndef JUMP_OPS_H
#define JUMP_OPS_H

#include "Stmt.h"

#include "Stmt.h"
class Opjump: public Stmt{   
    public: 
        Opjump() {};
        ~Opjump() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opjumpzero: public Stmt{   
    public: 
        Opjumpzero() {};
        ~Opjumpzero() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opjumpnzero: public Stmt{   
    public: 
        Opjumpnzero() {};
        ~Opjumpnzero() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

#endif
