#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	//OpCommand Code Here
public:
	OpCommand(int input) {
		root = new Op(input);
	}
};

class AddCommand : public Command {
	//AddCommand Code Here
public:
	AddCommand(Command* left, int input) { 
		root = new Add(left->get_root(), new Op(input));
	}
	// double execute() {
		// root->evaluate();
	// }

};

class SubCommand : public Command {
	//SubCommand Code Here
public:
	SubCommand(Command* left, int input) {
		root = new Sub(left->get_root(), new Op(input));
	}
};

class MultCommand : public Command {
	//MultCommand Code Here
public:
	MultCommand(Command* left, int input) {
		root = new Mult(left->get_root(), new Op(input));
	}
};

class SqrCommand : public Command {
	//SqrCommand Code Here
public:
	SqrCommand(Command* left) {
		root = new Sqr(left->get_root());
	}
};

#endif //__COMMAND_CLASS__
