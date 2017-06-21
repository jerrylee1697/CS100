#include "Collection.h"
/*The OperatorIterator will be used to iterate over composite nodes with two children. 
This means it’s first will initialize to the left child, and its next will cycle from 
left child (which is where it is set to start), to right child, then to NULL.*/

OperatorIterator::OperatorIterator(Base* ptr) :Iterator(ptr) {}

void OperatorIterator::first() {
	this->current_ptr = this->self_ptr->get_left();
}

void OperatorIterator::next() {
	if (this->current_ptr == this->self_ptr->get_left()) {
		this->current_ptr = this->self_ptr->get_right();
	}
	else {
		this->current_ptr = NULL;
	}
}

bool OperatorIterator::is_done() {
	if (current_ptr == NULL) {
		return true;
	}
	return false;
}

Base* OperatorIterator::current() {
	return this->current_ptr;
}

UnaryIterator::UnaryIterator(Base* ptr) : Iterator(ptr) {}

void UnaryIterator::first() {
	this->current_ptr = this->self_ptr->get_left();
}

void UnaryIterator::next() {
	if (this->current_ptr == this->self_ptr->get_left()) {
		// this->current_ptr = this->self_ptr->get_right();
		this->current_ptr = NULL;
	}
}

bool UnaryIterator::is_done() {
	if (this->current_ptr == NULL) {
		return true;
	}
	return false;
}

Base* UnaryIterator::current() {
	return this->current_ptr;
}

NullIterator::NullIterator(Base* ptr) : Iterator(ptr) {}

void NullIterator::first() {}	// Don't need to do anything

void NullIterator::next() {}	// Don't need to do anything

bool NullIterator::is_done() {
	return true;
}

Base* NullIterator::current() {
	return NULL;
}

PreOrderIterator::PreOrderIterator(Base* ptr) : Iterator(ptr) {}

void PreOrderIterator::first() {
	while (!iterators.empty()) {	// Empty stack incase not empty
		iterators.pop();
	}

	Iterator* it = this->self_ptr->create_iterator();
	it->first();
	iterators.push(it);

}

void PreOrderIterator::next() {
	Iterator* it = this->iterators.top()->current()->create_iterator();
	it->first();
	iterators.push(it);

	while (iterators.size() > 0 && iterators.top()->is_done()) {
		iterators.pop();
		if (iterators.size() > 0) {
			this->iterators.top()->next();
		}
	}

}

bool PreOrderIterator::is_done() {
	return iterators.empty();
}

Base* PreOrderIterator::current() {
	return iterators.top()->current();
}