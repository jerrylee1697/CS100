BaseFactory.cpp                                                                                     0000644 0601751 0601751 00000000457 13105112026 011773  0                                                                                                    ustar   jerry                                                                                                                                                                                                                                                  #include "BaseFactory.h"

BasePrint* DoubleFactory::generatePrint(double value) {
	return new DoublePrint(value);
}

BasePrint* HexFactory::generatePrint(double value) {
	return new HexPrint(value);
}

BasePrint* BinaryFactory::generatePrint(double value) {
	return new BinaryPrint(value);
}                                                                                                                                                                                                                 BasePrint.cpp                                                                                       0000644 0601751 0601751 00000002543 13105110066 011460  0                                                                                                    ustar   jerry                                                                                                                                                                                                                                                  #include "BasePrint.h"
using namespace std;
#include <iostream>
#include <bitset>

BasePrint::BasePrint() {}

BasePrint::BasePrint(double value) {
	this->value = value;
}

//-----------------------------------------------------
//---------------Class: DoublePrint--------------------
//-----------------------------------------------------

// DoublePrint::DoublePrint(double value) : BasePrint(value) {}
DoublePrint::DoublePrint() {

}

DoublePrint::DoublePrint(double value) {
	this->value = value;
}

void DoublePrint::print() {
	cout << this->value << endl;
}

//-----------------------------------------------------
//------------------Class: HexPrint--------------------
//-----------------------------------------------------
HexPrint::HexPrint() {}

HexPrint::HexPrint(double value) {
	this->value = value;
}

void HexPrint::print() {
	int x = (int)value;
	cout << hex << x << endl;	
}

//-----------------------------------------------------
//---------------Class: BinaryPrint--------------------
//-----------------------------------------------------
BinaryPrint::BinaryPrint() {}

BinaryPrint::BinaryPrint(double value) {
	this->value = value;
}
void BinaryPrint::print() {
	int x = (int)value;
	bitset<8> bitset(value);
	for (unsigned i = 0; i < bitset.size(); ++i) {
		cout << bitset[i];
	}
	cout << endl;
}                                                                                                                                                             container.cpp                                                                                       0000644 0601751 0601751 00000004536 13105120677 011570  0                                                                                                    ustar   jerry                                                                                                                                                                                                                                                  #include <iostream>
using namespace std;
#include <algorithm>
#include <stdexcept>
#include "sort.h"
#include "Base.h"
#include "container.h"

// void Container::set_sort_function(Sort* sort_function) {
// 	this->sort_function = sort_function;
// }

//Vector Container
void VectorContainer::add_element(Base* element) {
	container.push_back(element);
}

// void VectorContainer::print() {
// 	for (int i = 0; i < container.size(); ++i) {
// 		cout << container.at(i)->evaluate() << ' ';
// 	}
// 	cout << endl;
// }

// modified print to take BasePrint*
void VectorContainer::print() {
	BasePrint* a;
	for (int i = 0; i < container.size(); ++i) {
		// cout << container.at(i)->evaluate() << ' ';
		a = facType->generatePrint(container.at(i)->evaluate());
		a->print();
		cout << ' ';
	}
	cout << endl;
}

void VectorContainer::sort() {
	// set_sort_function(Sort* sort_function);
	if (sort_function == NULL) {
		throw logic_error("Sort_function empty when sort called.");
	}
	else {
		sort_function->sort(this);
	}
}

void VectorContainer::swap(int i, int j) {
	std::swap(container.at(i), container.at(j));
}

Base* VectorContainer::at(int i) {
	return container.at(i);
}

int VectorContainer::size() {
	return container.size();
}


//List Container---------------------------------------------------
// void ListContainer::set_sort_function(Sort* sort_function) {
// 	this->sort_function = sort_function;
// }

void ListContainer::add_element(Base* element) {
	baseList.push_back(element);
}

void ListContainer::print() {
	BasePrint* a;
	for (iterator1 = baseList.begin(); iterator1 != baseList.end(); iterator1++) {
		// cout << " " << (*iterator1)->evaluate();
		a = facType->generatePrint((*iterator1)->evaluate());
		a->print();
		cout << " ";
	}
	cout << endl;
}

void ListContainer::sort() {
	if (sort_function == NULL) {
		throw logic_error("Sort_function empty when sort called.");
	}
	else {
		sort_function->sort(this);
	}
}

void ListContainer::swap(int i, int j) {
	iterator1 = baseList.begin();
	iterator2 = baseList.begin();

	advance(iterator1,i);
	advance(iterator2,j);
	
	std::swap(*iterator1, *iterator2);
}

Base* ListContainer::at(int i) {
	iterator1 = baseList.begin();
	advance(iterator1, i);
	return *iterator1;
}
int ListContainer::size() {
	return baseList.size();
}                                                                                                                                                                  sort.cpp                                                                                            0000644 0601751 0601751 00000002042 13101600203 010543  0                                                                                                    ustar   jerry                                                                                                                                                                                                                                                  #include <cmath>
#include <iostream>
#include "sort.h"
#include "base.h"
#include "container.h"

void bubble::sort(Container* container) {
    while(true) {       // Continue percolating until no more swaps occur
        bool swapped = false;
        for (int i = 0; i < container->size() - 1; ++i) {
            if (container->at(i)->evaluate() > container->at(i + 1)->evaluate()) {
                container->swap(i, i + 1);
                swapped = true;
            }
        }
        if (!swapped) {
            return;
        }
    }
}


void selection::sort(Container* container) {
    
     //Base* temp=container->at(0);
    for(int i = 0;i < container->size()-1; i++){
        int j = i;
       // temp = container->at(i);
        int small = i;
        for( j = i; j < container->size(); j++){
            if( container->at(j)->evaluate() < container->at(small)->evaluate()){
                small=j;
            }
        }
        container->swap(i,small);
        //container->at(small) = temp;
    }
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              abstractMain.cpp                                                                                    0000644 0601751 0601751 00000003131 13105120434 012173  0                                                                                                    ustar   jerry                                                                                                                                                                                                                                                  //Lab 4: Strategy Pattern
//Name: Jerry Lee & Natasha Orie
//SID: 861208558

// #include necessary classes
#include <list>
#include <vector>
#include "container.h"
#include "Base.h"
#include "sort.h"
#include "BaseFactory.h"
#include "BasePrint.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string.h>

// #include "composite.h"
// #include "vector_container.h"
// #include "list_container.h"
// #include "strategy.h"
// #include "print.h"
// #include "factory.h"

using namespace std;

int main(int argc, char* argv[]) {
    
    /* Read in the input flag */
	char* s = argv[1];
    
    /* Create and set the Factory */
	BaseFactory* baf = NULL;
	if(strcmp(s,"d")==0){
		baf = new DoubleFactory();
	}else if(strcmp(s,"h")==0){
		baf = new HexFactory();
	}else{
		baf = new BinaryFactory();
	}
    
    /* Create the elements for testing */
	Op* op1 = new Op(5);
	Op* op2 = new Op(2);
	Op* op3 = new Op(4);
	Op* op4 = new Op(6);
	Mult* A = new Mult(op1, op2);
	Sub* B = new Sub(op3, op4);
	Add* C = new Add(A, B);
	Sqr* D = new Sqr(C);

    /* Save the elements to the container */
	VectorContainer* container = new VectorContainer(baf);
	container->add_element(A);
	container->add_element(B);
	container->add_element(D);
    
    /* Print the container before it is sorted */
	cout << "Container Before Sort: " << endl;
	container->print();
    
    /* Print the container after it is sorted */
    cout << "Container After Sort: " << endl;
	container->set_sort_function(new bubble());
	container->sort();
	container->print();
}
;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       