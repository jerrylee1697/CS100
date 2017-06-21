#ifndef DECORATORS_H
#define DECORATORS_H

#include "operations.h"

class Ceil : public Base {
public:
    Ceil(Base* child); 
    double evaluate();
private:
    Base* child;
};

class Floor : public Base {
public:
    Floor(Base* child);
    double evaluate();
private:
    Base* child;
};

class Abs : public Base {
public:
    Abs(Base* child);
    double evaluate();
private:
    Base* child;
};

#endif // DECORATORS_H