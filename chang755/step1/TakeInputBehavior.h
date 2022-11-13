#ifndef TAKEINPUTBEHAVIOR_H_
#define TAKEINPUTBEHAVIOR_H_

#include <iostream>
#include "TableEntry.h"
#include "SymbolTable.h"
#include "StringBuffer.h"

class TakeInputBehavior {
public:
   virtual int addToBuffer();
   virtual int addToBuffer(std::string str);
   virtual int addToBuffer(std::string str, StringBuffer* strBuffer);
   virtual int addToBuffer(std::string str, SymbolTable* sTable);
   virtual int addToBuffer(std::string var, std::string var2, SymbolTable* sTable);
   virtual ~TakeInputBehavior();
};

// class stmt_ops : public TakeInputBehavior {
// public:
//    virtual int addToBuffer() ;
//    virtual int addToBuffer(std::string str) ;
//    virtual int addToBuffer(std::string str, StringBuffer* strBuffer);
//    virtual int addToBuffer(std::string str, SymbolTable* sTable);
//    virtual int addToBuffer(std::string var, std::string var2, SymbolTable* sTable);
//    virtual ~stmt_ops() {};
// };

// class print_ops : public TakeInputBehavior {
// public:
//    virtual int addToBuffer();
//    virtual int addToBuffer(std::string str);
//    virtual int addToBuffer(std::string str, StringBuffer* strBuffer);
//    virtual int addToBuffer(std::string str, SymbolTable* sTable);
//    virtual int addToBuffer(std::string var, std::string var2, SymbolTable* sTable);
//    virtual ~print_ops() {};
// };

// class var_stmt_ops : public TakeInputBehavior {
// public:
//    virtual int addToBuffer();
//    virtual int addToBuffer(std::string str);
//    virtual int addToBuffer(std::string str, StringBuffer* strBuffer);
//    virtual int addToBuffer(std::string var, SymbolTable* sTable);
//    virtual int addToBuffer(std::string var, std::string var2, SymbolTable* sTable);
//    virtual ~var_stmt_ops() {};
// };

// class int_stmt_ops : public TakeInputBehavior {
// public:
//    virtual int addToBuffer();
//    virtual int addToBuffer(std::string str);
//    virtual int addToBuffer(std::string str, StringBuffer* strBuffer);
//    virtual int addToBuffer(std::string var, SymbolTable* sTable);
//    virtual int addToBuffer(std::string var, std::string var2, SymbolTable* sTable);
//    virtual ~int_stmt_ops() {};
// };

// class declscal_stmt_ops: public TakeInputBehavior {
// public:
//    virtual int addToBuffer();
//    virtual int addToBuffer(std::string str);
//    virtual int addToBuffer(std::string str, StringBuffer* strBuffer);
//    virtual int addToBuffer(std::string symbol, SymbolTable* sTable);
//    virtual int addToBuffer(std::string var, std::string var2, SymbolTable* sTable);
//    virtual ~declscal_stmt_ops() {};
// };

// class declarr_stmt_ops : public TakeInputBehavior {
// public:
//    virtual int addToBuffer();
//    virtual int addToBuffer(std::string str);
//    virtual int addToBuffer(std::string str, StringBuffer* strBuffer);
//    virtual int addToBuffer(std::string symbol, SymbolTable* sTable) {return 0;};
//    virtual int addToBuffer(std::string var, std::string var2, SymbolTable* sTable);
//    virtual ~declarr_stmt_ops() {};
// };

// class decllabel_stmt_ops : public TakeInputBehavior {
// public:
//    virtual int addToBuffer() { return 0; };
//    virtual int addToBuffer(std::string str) {return 0;};
//    virtual int addToBuffer(std::string str, StringBuffer* strBuffer) {return 0;};
//    virtual int addToBuffer(std::string symbol, SymbolTable* sTable);
//    virtual int addToBuffer(std::string var, std::string var2, SymbolTable* sTable) {return 0;};
//    virtual ~decllabel_stmt_ops() {};
// };

// class label_stmt_ops : public TakeInputBehavior {
// public:
//    virtual int addToBuffer();
//    virtual int addToBuffer(std::string symbol);
//    virtual int addToBuffer(std::string str, StringBuffer* strBuffer);
//    virtual int addToBuffer(std::string symbol, SymbolTable* sTable);
//    virtual int addToBuffer(std::string var, std::string var2, SymbolTable* sTable);
//    virtual ~label_stmt_ops() {};
// };

#endif /* TAKEINPUTBEHAVIOR_H_ */
