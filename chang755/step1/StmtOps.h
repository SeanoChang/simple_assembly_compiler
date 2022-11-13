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
