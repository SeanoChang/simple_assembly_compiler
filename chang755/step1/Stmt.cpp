#include <iostream>
#include "Stmt.h"
using namespace std;

/* Stmt pure virtual destructor */
Stmt::~Stmt() {}

/* op jump */
const int Opjump::opcode = OP_JUMP;
const std::string Opjump::operation= "Jump";

int Opjump::getOpcode(){
    return opcode;  
}

std::string Opjump::getOperation(){
    return operation;
}

/* op jumpzero */
const int Opjumpzero::opcode = OP_JUMPZERO;
const std::string Opjumpzero::operation= "JumpZero";

int Opjumpzero::getOpcode(){
    return opcode;  
}

std::string Opjumpzero::getOperation(){
    return operation;
}

/* op jumpnzero */
const int Opjumpnzero::opcode = OP_JUMPNZERO;
const std::string Opjumpnzero::operation= "JumpNZero";

int Opjumpnzero::getOpcode(){
    return opcode;  
}

std::string Opjumpnzero::getOperation(){
    return operation;
}

/* op gosub */
const int Opgosub::opcode = OP_GOSUB;
const std::string Opgosub::operation= "GoSub";

int Opgosub::getOpcode(){
    return opcode;  
}

std::string Opgosub::getOperation(){
    return operation;
}

/* op return */
const int Opreturn::opcode = OP_RETURN;
const std::string Opreturn::operation= "Return";

int Opreturn::getOpcode(){
    return opcode;  
}

std::string Opreturn::getOperation(){
    return operation;
}

/* op enter_subroutine */
const int Opentersubroutine::opcode = OP_ENTER_SUBROUTINE;
const std::string Opentersubroutine::operation= "EnterSubroutine";

int Opentersubroutine::getOpcode(){
    return opcode;  
}

std::string Opentersubroutine::getOperation(){
    return operation;
}

/* op exit_subroutine */
const int Opexitsubroutine::opcode = OP_EXIT_SUBROUTINE;
const std::string Opexitsubroutine::operation= "ExitSubroutine";

int Opexitsubroutine::getOpcode(){
    return opcode;  
}

std::string Opexitsubroutine::getOperation(){
    return operation;
}

/* op start_program */
const int Opstartprogram::opcode = OP_START_PROGRAM;
const std::string Opstartprogram::operation= "Start";

int Opstartprogram::getOpcode(){
    return opcode;  
}

std::string Opstartprogram::getOperation(){
    return operation;
}

/* op exit_program */
const int Opexitprogram::opcode = OP_EXIT_PROGRAM;
const std::string Opexitprogram::operation= "Exit";

int Opexitprogram::getOpcode(){
    return opcode;  
}

std::string Opexitprogram::getOperation(){
    return operation;
}

/* op pushscalar */
const int Oppushscalar::opcode = OP_PUSHSCALAR;
const std::string Oppushscalar::operation= "PushScalar";

int Oppushscalar::getOpcode(){
    return opcode;  
}

std::string Oppushscalar::getOperation(){
    return operation;
}

/* op pusharray */
const int Oppusharray::opcode = OP_PUSHARRAY;
const std::string Oppusharray::operation= "PushArray";

int Oppusharray::getOpcode(){
    return opcode;  
}

std::string Oppusharray::getOperation(){
    return operation;
}

/* op pushi */
const int Oppushi::opcode = OP_PUSHI;
const std::string Oppushi::operation= "PushI";

int Oppushi::getOpcode(){
    return opcode;  
}

std::string Oppushi::getOperation(){
    return operation;
}

/* op popscalar */
const int Oppopscalar::opcode = OP_POPSCALAR;
const std::string Oppopscalar::operation= "PopScalar";

int Oppopscalar::getOpcode(){
    return opcode;  
}

std::string Oppopscalar::getOperation(){
    return operation;
}

/* op poparray */
const int Oppoparray::opcode = OP_POPARRAY;
const std::string Oppoparray::operation= "PopArray";

int Oppoparray::getOpcode(){
    return opcode;  
}

std::string Oppoparray::getOperation(){
    return operation;
}

/* op pop */
const int Oppop::opcode = OP_POP;
const std::string Oppop::operation= "Pop";

int Oppop::getOpcode(){
    return opcode;  
}

std::string Oppop::getOperation(){
    return operation;
}

/* op dup */
const int Opdup::opcode = OP_DUP;
const std::string Opdup::operation= "Dup";

int Opdup::getOpcode(){
    return opcode;  
}

std::string Opdup::getOperation(){
    return operation;
}

/* op swap */
const int Opswap::opcode = OP_SWAP;
const std::string Opswap::operation= "Swap";

int Opswap::getOpcode(){
    return opcode;  
}

std::string Opswap::getOperation(){
    return operation;
}

/* op add */
const int Opadd::opcode = OP_ADD;
const std::string Opadd::operation= "Add";

int Opadd::getOpcode(){
    return opcode;  
}

std::string Opadd::getOperation(){
    return operation;
}

/* op negate */
const int Opnegate::opcode = OP_NEGATE;
const std::string Opnegate::operation= "Negate";

int Opnegate::getOpcode(){
    return opcode;  
}

std::string Opnegate::getOperation(){
    return operation;
}

/* op mul */
const int Opmul::opcode = OP_MUL;
const std::string Opmul::operation= "Mul";

int Opmul::getOpcode(){
    return opcode;  
}

std::string Opmul::getOperation(){
    return operation;
}

/* op div */
const int Opdiv::opcode = OP_DIV;
const std::string Opdiv::operation= "Div";

int Opdiv::getOpcode(){
    return opcode;  
}

std::string Opdiv::getOperation(){
    return operation;
}

/* op prints */
const int Opprints::opcode = OP_PRINTS;
const std::string Opprints::operation= "Prints";

int Opprints::getOpcode(){
    return opcode;  
}

std::string Opprints::getOperation(){
    return operation;
}

/* op printtos */
const int Opprinttos::opcode = OP_PRINTTOS;
const std::string Opprinttos::operation= "Printtos";

int Opprinttos::getOpcode(){
    return opcode;  
}

std::string Opprinttos::getOperation(){
    return operation;
}


/* op end program */
const int Opendprogram::opcode = 0;
const std::string Opendprogram::operation= "End";

int Opendprogram::getOpcode(){
    return opcode;  
}

std::string Opendprogram::getOperation(){
    return operation;
}

/* Opdeclarray */ 
const int Opdeclarray::opcode = 0;
const std::string Opdeclarray::operation= "DeclArray";

int Opdeclarray::getOpcode(){
    return opcode;  
}

std::string Opdeclarray::getOperation(){
    return operation;
}

/* Opdeclscalar */
const int Opdeclscalar::opcode = 0;
const std::string Opdeclscalar::operation= "DeclScalar";

int Opdeclscalar::getOpcode(){
    return opcode;  
}

std::string Opdeclscalar::getOperation(){
    return operation;
}

/* Oplabel */
const int Oplabel::opcode = 0;
const std::string Oplabel::operation= "Label";

int Oplabel::getOpcode(){
    return opcode;  
}

std::string Oplabel::getOperation(){
    return operation;
}

/* Opgosublabel */
const int Opgosublabel::opcode = 0;
const std::string Opgosublabel::operation= "GoSubLabel";

int Opgosublabel::getOpcode(){
    return opcode;  
}

std::string Opgosublabel::getOperation(){
    return operation;
}