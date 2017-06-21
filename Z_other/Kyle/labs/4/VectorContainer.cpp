#include <iostream>
#include <vector> 
#include <stdexcept>
#include "operations.h"
#include "Container.h"

void VectorContainer::set_sort_function(Sort* sort_function){
    
    this->sort_function = sort_function;

    
} // set the type of sorting algorithm
    
    /* Pure Virtual Functions */
    // push the top pointer of the tree into container
void VectorContainer::add_element(Base* element){
    
    BaseVector.push_back(element);
    
}
    // iterate through trees and output values
void VectorContainer::print(){
    
    
    for(unsigned int i = 0; i <  BaseVector.size(); i++){
        std::cout<<" "<< BaseVector.at(i)->evaluate();
    }
    std::cout<<std::endl;

    
}
    // calls on the previously set sorting-algorithm. Checks is sort_function is not null, throw exception if otherwise
void VectorContainer::sort() {
    if (sort_function == NULL) {
        throw std::logic_error("sort called when sort_function was empty");
    }
    else{
        
        sort_function->sort(this);
    }

}
    /* Essentially the only functions needed to sort */
    //switch tree locations
void VectorContainer::swap(int i, int j) {
    
    // Base* temp = BaseVector.at(i);
    // BaseVector.at(i) = BaseVector.at(j);
    // BaseVector.at(j) = temp;
    std::swap(BaseVector.at(i), BaseVector.at(j));
    
}
    // get top ptr of tree at index i
Base* VectorContainer::at(int i) {
    
    return BaseVector.at(i);
    
}
    // return container size
int VectorContainer::size(){
    
    return BaseVector.size();
    
    
}