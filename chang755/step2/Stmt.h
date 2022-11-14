#ifndef STMT_H
#define STMT_H

#include <string>

/* abstract class for all the instructions */
class Stmt {
    public:
        Stmt() {};
        virtual ~Stmt() = 0;
};

#endif
