//Jerry Lee
//Partner: Natasha Orie
//SID: 861208558


#include <iostream>
using namespace std;

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
		Op (double val) {
			this->val = val;
		};  
		virtual double evaluate () {
			return val;
		}
};

class Binary: public Base {
	protected:
		Base* left;
		Base* right;
		Binary (Base* a, Base* b) {
			left = a;
			right = b;
		}
};

class Mult: public Binary {
	public:
		// Mult (Base* a, Base* b) {
		// 	Binary (a, b);
		// }
		double evaluate () {
			return left->evaluate() * right->evaluate();
		}
};

class Div: public Binary {
	Base* left;
	Base* right;
	public:
		// Div (Base* a, Base* b) {
		// 	left = a;
		// 	right = b;
		// }
		double evaluate () {
			return left->evaluate() / right->evaluate();
		}
};

class Add: public Binary {
	public:
		// Add (Base* a, Base* b) {
		// 	left = a;
		// 	right = b;
		// }
		double evaluate () {
			return left->evaluate() + right->evaluate();
		}
};

class Sub: public Binary {
	public:
		// Sub (Base* a, Base* b) {
		// 	left = a;
		// 	right = b;
		// }
		double evaluate () {
			return left->evaluate() - right->evaluate();
		}
};

class Unary: public Base {
	public:
		Base* child;
};
class Sqr: public Unary {
	public:
		 Sqr (Base* a) {
		 	child = a;
		 }
		double evaluate() {
			return child->evaluate() * child->evaluate(); 
		}
};

int main () {
	Op seven(7);
	Op four(4);
	Mult multiplied(&seven, &four);
	Op three(3);
	Add add(&three, &multiplied);
	Op two(2);
	Sub sub(&add, &two);
	cout << sub.evaluate();
}