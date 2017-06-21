#include <iostream>
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

void VectorContainer::print() {
	for (int i = 0; i < container.size(); ++i) {
		cout << container.at(i)->evaluate() << ' ';
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
	for (iterator1 = baseList.begin(); iterator1 != baseList.end(); iterator1++) {
		cout << " " << (*iterator1)->evaluate();
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
}