#ifndef DUP_SWAP_H
#define DUP_SWAP_H

#include "Stmt.h"

class Opdup: public Stmt{   
    public: 
        Opdup() {};
        ~Opdup() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opswap: public Stmt{   
    public: 
        Opswap() {};
        ~Opswap() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

#endif
