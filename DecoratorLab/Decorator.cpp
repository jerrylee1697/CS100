#include "Decorator.h"
#include "math.h"

Ceiling::Ceiling(Base* element) {
	child = element;
}

double Ceiling::evaluate() {
	return ceil(child->evaluate());
}

Floor::Floor(Base* element) {
	child = element;
}

double Floor::evaluate() {
	return floor(child->evaluate());
}

Abs::Abs(Base* element) {
	child = element;
}

double Abs::evaluate () {
	return abs(child->evaluate());
}