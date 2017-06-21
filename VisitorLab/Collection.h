#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>
#include "Iterator.h"
#include "composite.h"
#include <stack>
using namespace std;

class OperatorIterator : public Iterator {
	public:
		OperatorIterator(Base* ptr);
 
		void first();
      	void next();
      	bool is_done();
      	Base* current();
};

class UnaryIterator : public Iterator {
	public:
		UnaryIterator(Base* ptr);
 
		void first();
       	void next();
       	bool is_done();
       	Base* current();
};

class NullIterator : public Iterator {
	public:
		NullIterator(Base* ptr);
 
		void first();
        void next();
        bool is_done();
        Base* current();
};

class PreOrderIterator : public Iterator {
	protected:
		stack<Iterator*> iterators;
 
	public:
		PreOrderIterator(Base* ptr);
 
		void first();
        void next();
       	bool is_done();
       	Base* current();
};

#endif