#ifndef SORT_H
#define SORT_H
#include "container.h"
#include "base.h"

class Container;


class Sort {
	public:
           /* Constructors */
		Sort() {};
		~Sort() {};
 
           /* Pure Virtual Functions */
		virtual void sort(Container* container) = 0;
};

class selection : public Sort {
	public:
		void sort(Container* container);
};

class bubble : public Sort {
	public:
		void sort(Container* container);
};

#endif