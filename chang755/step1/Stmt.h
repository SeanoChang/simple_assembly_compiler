#ifndef STMT_H
#define STMT_H

#include <string>
#include <iostream>
#include "TakeInputBehavior.h"

// list of static const int opcodes....
static const int OP_JUMP = 0x00000010;
static const int OP_JUMPZERO = 0x00000011;
static const int OP_JUMPNZERO = 0x00000012;
static const int OP_GOSUB = 0x00000013;
static const int OP_RETURN = 0x00000014;
static const int OP_ENTER_SUBROUTINE = 0x00000015; 
static const int OP_EXIT_SUBROUTINE = 0x00000016; 
static const int OP_START_PROGRAM = 0x00000017; 
static const int OP_EXIT_PROGRAM = 0x00000018;
static const int OP_PUSHSCALAR = 0x00000020; 
static const int OP_PUSHARRAY = 0x00000021; 
static const int OP_PUSHI = 0x00000022;
static const int OP_POPSCALAR = 0x00000030; 
static const int OP_POPARRAY = 0x00000031; 
static const int OP_POP = 0x00000032;
static const int OP_DUP = 0x00000040; 
static const int OP_SWAP = 0x00000041;
static const int OP_ADD = 0x00000050; 
static const int OP_NEGATE = 0x00000051; 
static const int OP_MUL = 0x00000052; 
static const int OP_DIV = 0x00000053;
static const int OP_PRINTS = 0x00000060; 
static const int OP_PRINTTOS = 0x00000061;

class Stmt{
public:
    Stmt() {};
    virtual int getOpcode() = 0;
    virtual std::string getOperation() = 0;
    virtual ~Stmt() = 0;
    virtual void setTakeInputBehavior(TakeInputBehavior* takeInputBehavior);
    virtual int takeInput(std::string input);
    virtual int takeInput(std::string input, StringBuffer* stringBuffer);
    virtual int takeInput(std::string input, SymbolTable* symbolTable);
    virtual int takeInput(std::string input1, std::string input2, SymbolTable* symbolTable);
protected: 
    int locationInBuffer;
    TakeInputBehavior* takeInputBehavior;
};

class Opjump: public Stmt
{   
    public: 
        Opjump();
        ~Opjump() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opjumpzero: public Stmt
{   
    public: 
        Opjumpzero();
        ~Opjumpzero() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opjumpnzero: public Stmt
{   
    public: 
        Opjumpnzero();
        ~Opjumpnzero() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opgosub: public Stmt
{   
    public: 
        Opgosub();
        ~Opgosub() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opreturn: public Stmt
{   
    public: 
        Opreturn();
        ~Opreturn() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opentersubroutine: public Stmt
{   
    public: 
        Opentersubroutine();
        ~Opentersubroutine() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opexitsubroutine: public Stmt
{   
    public: 
        Opexitsubroutine() ;
        ~Opexitsubroutine() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opstartprogram: public Stmt
{   
    public: 
        Opstartprogram() ;
        ~Opstartprogram() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opexitprogram: public Stmt
{   
    public: 
        Opexitprogram() ;
        ~Opexitprogram() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Oppushscalar: public Stmt
{   
    public: 
        Oppushscalar() ;
        ~Oppushscalar() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Oppusharray: public Stmt
{   
    public: 
        Oppusharray() ;
        ~Oppusharray() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Oppushi: public Stmt
{   
    public: 
        Oppushi() ;
        ~Oppushi() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Oppopscalar: public Stmt
{   
    public: 
        Oppopscalar() ;
        ~Oppopscalar() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Oppoparray: public Stmt
{   
    public: 
        Oppoparray() ;
        ~Oppoparray() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Oppop: public Stmt
{   
    public: 
        Oppop() ;
        ~Oppop() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opdup: public Stmt
{   
    public: 
        Opdup() ;
        ~Opdup() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opswap: public Stmt
{   
    public: 
        Opswap() ;
        ~Opswap() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opadd: public Stmt
{   
    public: 
        Opadd() ;
        ~Opadd() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opnegate: public Stmt
{   
    public: 
        Opnegate() ;
        ~Opnegate() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opmul: public Stmt
{   
    public: 
        Opmul() ;
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
        Opdiv() ;
        ~Opdiv() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opprints: public Stmt
{   
    public: 
        Opprints() ;
        ~Opprints() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opprinttos: public Stmt
{   
    public: 
        Opprinttos() ;
        ~Opprinttos() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opendprogram: public Stmt
{   
    public: 
        Opendprogram() ;
        ~Opendprogram() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opdeclarray: public Stmt
{   
    public: 
        Opdeclarray() ;
        ~Opdeclarray() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opdeclscalar: public Stmt
{   
    public: 
        Opdeclscalar() ;
        ~Opdeclscalar() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Oplabel: public Stmt
{   
    public: 
        Oplabel() ;
        ~Oplabel() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

class Opgosublabel: public Stmt
{   
    public: 
        Opgosublabel() ;
        ~Opgosublabel() {};
        int getOpcode();
        std::string getOperation();
        
    private:
        static const int opcode;
        static const std::string operation;
};

#endif 
