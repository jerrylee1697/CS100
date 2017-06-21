#ifndef DECORATOR_H
#define DECORATOR_H

#include "Base.h"

class Decorator: public Base {
	public:
		virtual double evaluate() = 0;
	protected:
		Base* child;
};

class Ceiling : public Decorator {
	public:
		double evaluate();
		Ceiling(Base* element);
};

class Floor : public Decorator {
	public: 
		double evaluate();
		Floor(Base* element);
};

class Abs : public Decorator {
	public:
		double evaluate();
		Abs(Base* element);
};

#endif