#ifndef CONTAINER_H
#define CONTAINER_H


using namespace std;
#include <iostream>
#include <vector>
#include <list>
#include "sort.h"
#include "Base.h"
#include "BaseFactory.h"
#include "BasePrint.h"

class Sort;

class Container {
    protected:
        Sort* sort_function;
        BaseFactory* facType;

    public:
	   /* Constructors */
        Container() : sort_function(NULL){};
        Container(Sort* function) : sort_function(function) {};
        Container(BaseFactory* facType) : facType(facType) {};

        /* Non Virtual Functions */
        void set_sort_function(Sort* sort_function); // set the type of sorting algorithm

        /* Pure Virtual Functions */
		// push the top pointer of the tree into container
        virtual void add_element(Base* element) = 0; 
        // iterate through trees and output values
  		virtual void print() = 0; 
  		// calls on the previously set sorting-algorithm. Checks if                   sort_function is not null, throw exception if otherwise
        virtual void sort() = 0; 

        /* Essentially the only functions needed to sort */
        //switch tree locations
  		virtual void swap(int i, int j) = 0; 
        // get top ptr of tree at index i
  		virtual Base* at(int i) = 0; 
        // return container size
  		virtual int size() = 0; 
};

class VectorContainer: public Container {
	private:
		vector<Base*> container;
	public:
		// void set_sort_function(Sort* sort_function);
		VectorContainer(BaseFactory* facType) : Container(facType) {};
		void set_sort_function(Sort* sort_function) {
			this->sort_function = sort_function;
		}
		void add_element(Base* element);
		void print();
		void sort();
		void swap(int i, int j);
		Base* at(int i);
		int size();
};

class ListContainer: public Container {
	private:
		list<Base*> baseList;
		list<Base*>::iterator iterator1;
		list<Base*>::iterator iterator2;
	public:
		// void set_sort_function(Sort* sort_function);
		ListContainer(BaseFactory* facType) : Container(facType) {};
		void set_sort_function(Sort* sort_function) {
			this->sort_function = sort_function;
		}
		void add_element(Base* element);
		void print();
		void sort();
		void swap(int i, int j);
		Base* at(int i);
		int size();
};

#endif