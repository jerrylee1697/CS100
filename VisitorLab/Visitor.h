#ifndef VISITOR_H
#define VISITOR_H

#include <iostream>
using namespace std;

// class PrintVisitor;
#include "PrintVisitor.h"
#include "composite.h"

class Visitor {
	private:

	public:
		// Visitor();

		virtual void rootNode() = 0;
		virtual void sqrNode() = 0;
		virtual void multNode() = 0;
		virtual void subNode() = 0;
		virtual void addNode() = 0;
		virtual void opNode(Op* op) = 0;

		virtual void execute() = 0;

};

#endif 