#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "ExecuteBehavior.h"

class Instruction{
public:
    Instruction() {};
    virtual ~Instruction() = 0;
protected: 
    int locationInBuffer;
    ExecuteBehavior* executeBehavior;
};

class OP_ENTER_SUBROUTINE: public Instruction{};
class OP_START_PROGRAM: public Instruction{};
class OP_EXIT: public Instruction{};
class OP_JUMP: public Instruction{};
class OP_JUMPZERO: public Instruction{};
class OP_JUMPNZERO: public Instruction{};
class OP_GOSUB: public Instruction{};
class OP_RETURN: public Instruction{};
class OP_GOSUB: public Instruction{};
class OP_PUSHSCALAR: public Instruction{};
class OP_PUSHARRAY: public Instruction{};
class OP_PUSHI: public Instruction{};
class OP_POP: public Instruction{};
class OP_POP_SCALAR: public Instruction{};
class OP_POP_ARRAY: public Instruction{};
class OP_DUP: public Instruction{};
class OP_SWAP: public Instruction{};
class OP_ADD: public Instruction{};
class OP_NEGATE: public Instruction{};
class OP_MUL: public Instruction{};
class OP_DIV: public Instruction{};
class OP_PRINTS: public Instruction{};
class OP_PRINTTOS: public Instruction{};

#endif
