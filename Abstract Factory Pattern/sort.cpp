#include <cmath>
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
