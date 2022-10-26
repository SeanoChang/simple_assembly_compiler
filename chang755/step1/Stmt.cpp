#include <iostream>

#include "Stmt.h"
using namespace std;

/* Stmt pure virtual destructor */
Stmt::~Stmt() {
    delete takeInputBehavior;
}

void Stmt::setTakeInputBehavior(TakeInputBehavior* _takeInputBehavior) {
   takeInputBehavior = _takeInputBehavior;
}

int Stmt::takeInput(std::string input) {
   return takeInputBehavior->addToBuffer(input);
}

int Stmt::takeInput(std::string input, StringBuffer* stringBuffer) {
    return takeInputBehavior->addToBuffer(input, stringBuffer);
}

int Stmt::takeInput(std::string input, SymbolTable* symbolTable) {
    return takeInputBehavior->addToBuffer(input, symbolTable);
}

int Stmt::takeInput(std::string input1, std::string input2, SymbolTable* symbolTable) {
    return takeInputBehavior->addToBuffer(input1, input2, symbolTable);
}

/* op jump */
const int Opjump::opcode = OP_JUMP;
const std::string Opjump::operation= "Jump";

Opjump::Opjump() {
    takeInputBehavior = new label_stmt_ops();
}

int Opjump::getOpcode(){
    return opcode;  
}

std::string Opjump::getOperation(){
    return operation;
}


/* op jumpzero */
const int Opjumpzero::opcode = OP_JUMPZERO;
const std::string Opjumpzero::operation= "JumpZero";

Opjumpzero::Opjumpzero() {
    takeInputBehavior = new label_stmt_ops();
}

int Opjumpzero::getOpcode(){
    return opcode;  
}

std::string Opjumpzero::getOperation(){
    return operation;
}

/* op jumpnzero */
const int Opjumpnzero::opcode = OP_JUMPNZERO;
const std::string Opjumpnzero::operation= "JumpNZero";

Opjumpnzero::Opjumpnzero() {
    takeInputBehavior = new label_stmt_ops();
}

int Opjumpnzero::getOpcode(){
    return opcode;  
}

std::string Opjumpnzero::getOperation(){
    return operation;
}

/* op gosub */
const int Opgosub::opcode = OP_GOSUB;
const std::string Opgosub::operation= "GoSub";

Opgosub::Opgosub() {
    takeInputBehavior = new label_stmt_ops();
}

int Opgosub::getOpcode(){
    return opcode;  
}

std::string Opgosub::getOperation(){
    return operation;
}

/* op return */
const int Opreturn::opcode = OP_RETURN;
const std::string Opreturn::operation= "Return";

Opreturn::Opreturn() {
    takeInputBehavior = new stmt_ops();
}

int Opreturn::getOpcode(){
    return opcode;  
}

std::string Opreturn::getOperation(){
    return operation;
}

/* op enter_subroutine */
const int Opentersubroutine::opcode = OP_ENTER_SUBROUTINE;
const std::string Opentersubroutine::operation= "EnterSubroutine";

Opentersubroutine::Opentersubroutine() {
    takeInputBehavior = new decllabel_stmt_ops();
}

int Opentersubroutine::getOpcode(){
    return opcode;  
}

std::string Opentersubroutine::getOperation(){
    return operation;
}

/* op exit_subroutine */
const int Opexitsubroutine::opcode = OP_EXIT_SUBROUTINE;
const std::string Opexitsubroutine::operation= "ExitSubroutine";

Opexitsubroutine::Opexitsubroutine() {
    takeInputBehavior = new decllabel_stmt_ops();
}

int Opexitsubroutine::getOpcode(){
    return opcode;  
}

std::string Opexitsubroutine::getOperation(){
    return operation;
}

/* op start_program */
const int Opstartprogram::opcode = OP_START_PROGRAM;
const std::string Opstartprogram::operation= "Start";

Opstartprogram::Opstartprogram() {
    takeInputBehavior = new stmt_ops();
}

int Opstartprogram::getOpcode(){
    return opcode;  
}

std::string Opstartprogram::getOperation(){
    return operation;
}

/* op exit_program */
const int Opexitprogram::opcode = OP_EXIT_PROGRAM;
const std::string Opexitprogram::operation= "Exit";

Opexitprogram::Opexitprogram() {
    takeInputBehavior = new stmt_ops();
}

int Opexitprogram::getOpcode(){
    return opcode;  
}

std::string Opexitprogram::getOperation(){
    return operation;
}

/* op pushscalar */
const int Oppushscalar::opcode = OP_PUSHSCALAR;
const std::string Oppushscalar::operation= "PushScalar";

Oppushscalar::Oppushscalar() {
    takeInputBehavior = new var_stmt_ops();
}

int Oppushscalar::getOpcode(){
    return opcode;  
}

std::string Oppushscalar::getOperation(){
    return operation;
}

/* op pusharray */
const int Oppusharray::opcode = OP_PUSHARRAY;
const std::string Oppusharray::operation= "PushArray";

Oppusharray::Oppusharray() {
    takeInputBehavior = new var_stmt_ops();
}

int Oppusharray::getOpcode(){
    return opcode;  
}

std::string Oppusharray::getOperation(){
    return operation;
}

/* op pushi */
const int Oppushi::opcode = OP_PUSHI;
const std::string Oppushi::operation= "PushI";

Oppushi::Oppushi() {
    takeInputBehavior = new int_stmt_ops();
}

int Oppushi::getOpcode(){
    return opcode;  
}

std::string Oppushi::getOperation(){
    return operation;
}

/* op popscalar */
const int Oppopscalar::opcode = OP_POPSCALAR;
const std::string Oppopscalar::operation= "PopScalar";

Oppopscalar::Oppopscalar() {
    takeInputBehavior = new var_stmt_ops();
}

int Oppopscalar::getOpcode(){
    return opcode;  
}

std::string Oppopscalar::getOperation(){
    return operation;
}

/* op poparray */
const int Oppoparray::opcode = OP_POPARRAY;
const std::string Oppoparray::operation= "PopArray";

Oppoparray::Oppoparray() {
    takeInputBehavior = new var_stmt_ops();
}

int Oppoparray::getOpcode(){
    return opcode;  
}

std::string Oppoparray::getOperation(){
    return operation;
}

/* op pop */
const int Oppop::opcode = OP_POP;
const std::string Oppop::operation= "Pop";

Oppop::Oppop() {
    takeInputBehavior = new stmt_ops();
}

int Oppop::getOpcode(){
    return opcode;  
}

std::string Oppop::getOperation(){
    return operation;
}

/* op dup */
const int Opdup::opcode = OP_DUP;
const std::string Opdup::operation= "Dup";

Opdup::Opdup() {
    takeInputBehavior = new stmt_ops();
}

int Opdup::getOpcode(){
    return opcode;  
}

std::string Opdup::getOperation(){
    return operation;
}

/* op swap */
const int Opswap::opcode = OP_SWAP;
const std::string Opswap::operation= "Swap";

Opswap::Opswap() {
    takeInputBehavior = new stmt_ops();
}

int Opswap::getOpcode(){
    return opcode;  
}

std::string Opswap::getOperation(){
    return operation;
}

/* op add */
const int Opadd::opcode = OP_ADD;
const std::string Opadd::operation= "Add";

Opadd::Opadd() {
    takeInputBehavior = new stmt_ops();
}

int Opadd::getOpcode(){
    return opcode;  
}

std::string Opadd::getOperation(){
    return operation;
}

/* op negate */
const int Opnegate::opcode = OP_NEGATE;
const std::string Opnegate::operation= "Negate";

Opnegate::Opnegate() {
    takeInputBehavior = new stmt_ops();
}

int Opnegate::getOpcode(){
    return opcode;  
}

std::string Opnegate::getOperation(){
    return operation;
}

/* op mul */
const int Opmul::opcode = OP_MUL;
const std::string Opmul::operation= "Mul";

Opmul::Opmul() {
    takeInputBehavior = new stmt_ops();
}

int Opmul::getOpcode(){
    return opcode;  
}

std::string Opmul::getOperation(){
    return operation;
}

/* op div */
const int Opdiv::opcode = OP_DIV;
const std::string Opdiv::operation= "Div";

Opdiv::Opdiv() {
    takeInputBehavior = new stmt_ops();
}

int Opdiv::getOpcode(){
    return opcode;  
}

std::string Opdiv::getOperation(){
    return operation;
}

/* op prints */
const int Opprints::opcode = OP_PRINTS;
const std::string Opprints::operation= "Prints";

Opprints::Opprints() {
    takeInputBehavior = new stmt_ops();
}

int Opprints::getOpcode(){
    return opcode;  
}

std::string Opprints::getOperation(){
    return operation;
}

/* op printtos */
const int Opprinttos::opcode = OP_PRINTTOS;
const std::string Opprinttos::operation= "PrintTOS";

Opprinttos::Opprinttos() {
    takeInputBehavior = new stmt_ops();
}

int Opprinttos::getOpcode(){
    return opcode;  
}

std::string Opprinttos::getOperation(){
    return operation;
}

/* op end program */
const int Opendprogram::opcode = 0;
const std::string Opendprogram::operation= "End";

Opendprogram::Opendprogram() {
    takeInputBehavior = new stmt_ops();
}

int Opendprogram::getOpcode(){
    return opcode;  
}

std::string Opendprogram::getOperation(){
    return operation;
}

/* Opdeclarray */ 
const int Opdeclarray::opcode = 0;
const std::string Opdeclarray::operation= "DeclArray";

Opdeclarray::Opdeclarray(){
    takeInputBehavior = new declarr_stmt_ops();
}

int Opdeclarray::getOpcode(){
    return opcode;  
}

std::string Opdeclarray::getOperation(){
    return operation;
}

/* Opdeclscalar */
const int Opdeclscalar::opcode = 0;
const std::string Opdeclscalar::operation= "DeclScalar";

Opdeclscalar::Opdeclscalar(){
    takeInputBehavior = new declscal_stmt_ops();
}

int Opdeclscalar::getOpcode(){
    return opcode;  
}

std::string Opdeclscalar::getOperation(){
    return operation;
}

/* Oplabel */
const int Oplabel::opcode = 0;
const std::string Oplabel::operation= "Label";

Oplabel::Oplabel(){
    takeInputBehavior = new decllabel_stmt_ops();
}

int Oplabel::getOpcode(){
    return opcode;  
}

std::string Oplabel::getOperation(){
    return operation;
}

/* Opgosublabel */
const int Opgosublabel::opcode = 0;
const std::string Opgosublabel::operation= "GoSubLabel";

Opgosublabel::Opgosublabel(){
    takeInputBehavior = new decllabel_stmt_ops();
}

int Opgosublabel::getOpcode(){
    return opcode;  
}

std::string Opgosublabel::getOperation(){
    return operation;
}
