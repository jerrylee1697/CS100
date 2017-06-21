#ifndef CONTAINER_H
#define CONTAINER_H
#include <vector>
#include <list>
#include "Sort.h"
#include "operations.h"

class Sort;

class Container {
protected:
    Sort* sort_function;
    
public:
    /* Constructors */
    Container() : sort_function(NULL){};
    Container(Sort* function) : sort_function(function) {};
    
    /* Non Virtual Functions */
    void set_sort_function(Sort* sort_function); // set the type of sorting algorithm
    
    /* Pure Virtual Functions */
    // push the top pointer of the tree into container
    virtual void add_element(Base* element) = 0;
    // iterate through trees and output values
    virtual void print() = 0;
    // calls on the previously set sorting-algorithm. Checks is sort_function is not null, throw exception if otherwise
    virtual void sort() = 0;
    /* Essentially the only functions needed to sort */
    //switch tree locations
    virtual void swap(int i, int j) = 0;
    // get top ptr of tree at index i
    virtual Base* at(int i) = 0;
    // return container size
    virtual int size() = 0;
};

class VectorContainer : public Container {
private:
    std::vector<Base*> BaseVector;
     
     
public:
     /* Non Virtual Functions */
    void set_sort_function(Sort* sort_function); // set the type of sorting algorithm
    
    /* Pure Virtual Functions */
    // push the top pointer of the tree into container
    void add_element(Base* element);
    // iterate through trees and output values
    void print();
    // calls on the previously set sorting-algorithm. Checks is sort_function is not null, throw exception if otherwise
    void sort() ;
    /* Essentially the only functions needed to sort */
    //switch tree locations
    void swap(int i, int j) ;
    // get top ptr of tree at index i
    Base* at(int i) ;
    // return container size
    int size();
    
};

class ListContainer : public Container {
     private:
        std::list<Base*> BaseList;
        std::list<Base*>::iterator Iterator1;
        std::list<Base*>::iterator Iterator2;
     
     public:
     /* Non Virtual Functions */
    void set_sort_function(Sort* sort_function); // set the type of sorting algorithm
    
    /* Pure Virtual Functions */
    // push the top pointer of the tree into container
    void add_element(Base* element);
    // iterate through trees and output values
    void print();
    // calls on the previously set sorting-algorithm. Checks is sort_function is not null, throw exception if otherwise
    void sort() ;
    /* Essentially the only functions needed to sort */
    //switch tree locations
    void swap(int i, int j) ;
    // get top ptr of tree at index i
    Base* at(int i) ;
    // return container size
    int size();
    
};

#endif // CONTAINER_H