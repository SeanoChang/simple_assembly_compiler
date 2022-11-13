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