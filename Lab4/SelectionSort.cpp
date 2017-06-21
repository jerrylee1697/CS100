#include <cmath> 
#include <iostream>
#include "Sort.h"
#include "operations.h"
#include "Container.h"

void SelectionSort::sort(Container* container) {
    
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
