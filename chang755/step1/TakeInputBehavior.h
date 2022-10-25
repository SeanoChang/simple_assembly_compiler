#ifndef INPUTREQUIRED_H_
#define INPUTREQUIRED_H_

class TakeInputBehavior {
public:
   virtual void push( ) = 0;
};

class stmt_ops : public TakeInputBehavior {
public:
   void push( );
};

class var_stmt_ops : public TakeInputBehavior {
public:
   void push( );
};

class int_stmt_ops : public TakeInputBehavior {
public:
   void push( );
};

class varLen_stmt_ops : public TakeInputBehavior {
public:
   void push( );
};

class label_stmt_ops : public TakeInputBehavior {
public:
   void push( );
};

class stmt_ops_list : public TakeInputBehavior {
public:
   void push( );
};

#endif /* INPUTREQUIRED_H_ */