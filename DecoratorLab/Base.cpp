using namespace std;
#include <iostream>
#include <cmath>
#include "Base.h"



Op::Op (double val) {
	this->val = val;
};  
double Op::evaluate () {
	return val;
}

Mult::Mult (Base* a, Base* b) {
	left = a;
	right = b;
}
double Mult::evaluate () {
	return left->evaluate() * right->evaluate();
}




Div::Div (Base* a, Base* b) {
	left = a;
	right = b;
}
double Div::evaluate () {
	return left->evaluate() / right->evaluate();
}



Add::Add (Base* a, Base* b) {
	left = a;
	right = b;
}
double Add::evaluate () {
	return left->evaluate() + right->evaluate();
}


Sub::Sub (Base* a, Base* b) {
	left = a;
	right = b;
}
double Sub::evaluate () {
	return left->evaluate() - right->evaluate();
}



Sqr::Sqr (Base* a) {
 	child = a;
 }
double Sqr::evaluate() {
	return child->evaluate() * child->evaluate(); 
}
