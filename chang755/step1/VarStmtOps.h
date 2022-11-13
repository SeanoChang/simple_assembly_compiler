#ifndef VAR_STMT_OPS_H_
#define VAR_STMT_OPS_H_

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

#endif
