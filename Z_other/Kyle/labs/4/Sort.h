#ifndef SORT_H
#define SORT_H
#include "operations.h"
#include "Container.h"
class Container;

class Sort {
public:
    /* Constructors */
    Sort() {};
    ~Sort();
    /* Pure Virtual Functions */
    virtual void sort(Container* container) = 0;
};

class SelectionSort : public Sort {
public:
   void sort(Container* container); 
};

class BubbleSort : public Sort {
public:
    void sort(Container* container);
    
};

#endif // SORT_H
