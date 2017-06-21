#include <cmath>
#include <iostream>
#include "Sort.h"
#include "operations.h"
#include "Container.h"

void BubbleSort::sort(Container* container) {
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
