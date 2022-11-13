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