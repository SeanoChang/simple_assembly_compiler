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