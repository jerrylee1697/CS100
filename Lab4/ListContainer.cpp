#include <iostream>     // std::cout, std::endl
#include <algorithm>    // std::swap
#include <stdexcept>
#include "operations.h"
#include "Container.h"

void ListContainer::set_sort_function(Sort* sort_function){ // set the type of sorting algorithm

    this->sort_function=sort_function;
    
}
   
    // push the top pointer of the tree into container
void ListContainer::add_element(Base* element){
     
     BaseList.push_front(element);
    
    
}
    // iterate through trees and output values
void ListContainer::print(){
    
    for (Iterator1 = BaseList.begin(); Iterator1 != BaseList.end(); Iterator1++){
        std::cout<<" "<< (*Iterator1)->evaluate();
    }
    std::cout<<std::endl;
    
    
}
    // calls on the previously set sorting-algorithm. Checks is sort_function is not null, throw exception if otherwise
void ListContainer::sort(){
    
    if (sort_function==NULL){
         throw std::logic_error("sort called when sort_function was empty");
    }
    else{
        sort_function->sort(this);
    }
    
}
    
    //switch tree locations
void ListContainer::swap(int i, int j) {
    Iterator1 = BaseList.begin();
    Iterator2 = BaseList.begin();
    std::advance(Iterator1,i);
    std::advance(Iterator2,j);
    
    // Base* temp = *Iterator1;
    // Iterator1 = *Iterator2;
    // Iterator2 = *temp;
    std::swap(*Iterator1, *Iterator2);
    
}

    // get top ptr of tree at index i
Base* ListContainer::at(int i) {
    Iterator1 = BaseList.begin();
    std::advance(Iterator1, i);
    return *Iterator1;
}

// return container size
int ListContainer::size(){
    
    return BaseList.size();
    
    
}