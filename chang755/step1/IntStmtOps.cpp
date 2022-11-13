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