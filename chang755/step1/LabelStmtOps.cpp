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