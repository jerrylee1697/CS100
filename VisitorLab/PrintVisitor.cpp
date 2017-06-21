#include "PrintVisitor.h"

PrintVisitor::PrintVisitor() {
	this->output = "";
}

void PrintVisitor::sqrNode() {
	output.append('*');
}

void PrintVisitor::sqrNode() {
	output.append('^');
}

void PrintVisitor::multNode() {
	output.append('*');
}

void PrintVisitor::subNode() {
	output.append('-');
}

void PrintVisitor::addNode() {
	output.append('+');
}

void PrintVisitor::opNode(Op* op) {
	output.append(to_string(op));
}

void PrintVisitor::execute() {
	cout << output << endl;
}