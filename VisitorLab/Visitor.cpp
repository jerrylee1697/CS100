#include "Visitor.h"

// void Operator::accept(Visitor* v) {
// 	v.opNode(Op* op);
// }

void Sqr::accept(Visitor* v) {
	v.sqrNode();
}

void Mult::accept(Visitor* v) {
	v.multNode();
}

void Sub::accept(Visitor* v) {
	v.subNode();
}

void Add::accept(Visitor* v) {
	v.addNode();
}

void Operator::accept(Visitor* v) {
	v.opNode(this);
}