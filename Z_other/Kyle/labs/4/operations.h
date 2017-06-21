#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <cmath>
#include <iostream>
#include <cstdlib>

class Base {
    
public:
    // Constructors //
    Base() { }
    // Pure Virtual Functions //
    virtual double evaluate() = 0;
protected:
    Base* leftChild;
    Base* rightChild;
};

class Op: public Base{
    public:
    Op();
    Op(double);
    void set(double);
    double evaluate();
    
    private:
    double value;
};

class  Mult: public Base{
    public:
    Mult();
    Mult(Base*, Base*);
    double evaluate();
    // void addChilds(Base*, Base*);
    
    // private:
    // Base* leftChild;
    // Base* rightChild;
};

class  Div: public Base{
    public:
    Div();
    Div(Base*, Base*);
    double evaluate();
    // void addChilds(Base*, Base*);    
    
    private:
    Base* leftChild;
    Base* rightChild;
};

class  Add: public Base{
    public:
    Add();
    Add(Base*, Base*);
    double evaluate();
    // void addChilds(Base*, Base*);
    
    private:
    Base* leftChild;
    Base* rightChild;
};

class  Sub: public Base{
   public:
   Sub();
    Sub(Base*, Base*);
    double evaluate();
    // void addChilds(Base*, Base*);
    
    private:
    Base* leftChild;
    Base* rightChild;
};

class  Sqr: public Base{
public:
    Sqr();
    Sqr(Base*);
    double evaluate();
    // void addChilds(Base*);
    // void addChilds(Base * child, Base* child2);
private:
    Base* child;
};

#endif // OPERATIONS_H