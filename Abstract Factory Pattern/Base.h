#ifndef BASE_H
#define BASE_H
#include <cmath>
#include <cstdlib>
using namespace std;
#include <iostream>

class Base {
    public:
        /* Constructors */
        Base() { };


        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
};

class Op: public Base {
	double val;
	public:
		Op (double val);  
		virtual double evaluate ();
};

class Binary: public Base {
	protected:
		Base* left;
		Base* right;
		// Binary (Base* a, Base* b) {
		// 	left = a;
		// 	right = b;
		// }
};

class Mult: public Binary {
	public:
		Mult (Base* a, Base* b);
		double evaluate ();
};

class Div: public Binary {
	// Base* left;
	// Base* right;
	public:
		Div (Base* a, Base* b);
		double evaluate ();
};

class Add: public Binary {
	public:
		Add (Base* a, Base* b);
		double evaluate ();
};

class Sub: public Binary {
	public:
		Sub (Base* a, Base* b);
		double evaluate ();
};

class Unary: public Base {
	public:
		Base* child;
};
class Sqr: public Unary {
	public:
		Sqr (Base* a);
		double evaluate();
};

#endif