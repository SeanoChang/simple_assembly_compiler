#ifndef STMT_OPS_H_
#define STMT_OPS_H_

#include "Stmt.h"

class Oppushscalar: public Stmt{   
    public: 
        Oppushscalar() {};
        ~Oppushscalar() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Oppusharray: public Stmt{   
    public: 
        Oppusharray() {};
        ~Oppusharray() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

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
