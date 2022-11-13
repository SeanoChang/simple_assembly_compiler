#ifndef LABEL_STMT_OPS_H_
#define LABEL_STMT_OPS_H_

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

#endif
