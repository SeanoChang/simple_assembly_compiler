#ifndef STMT_OPS_H_
#define STMT_OPS_H_

#include "Stmt.h"

class Opreturn: public Stmt{   
    public: 
        Opreturn() {};
        ~Opreturn() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opstartprogram: public Stmt{   
    public: 
        Opstartprogram() {};
        ~Opstartprogram() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opexitprogram: public Stmt{   
    public: 
        Opexitprogram() {};
        ~Opexitprogram() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opendprogram: public Stmt{   
    public: 
        Opendprogram() {};
        ~Opendprogram() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

#endif