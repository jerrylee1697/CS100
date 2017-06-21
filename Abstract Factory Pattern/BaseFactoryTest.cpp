#include <iostream>
using namespace std;
#include "BaseFactory.h"
#include "BasePrint.h"

int main() {
	DoubleFactory db;
	BasePrint* testDB = db.generatePrint(11.6);
	testDB->print();

	HexFactory hx;
	BasePrint* testHX = hx.generatePrint(10);
	testHX->print();

	BinaryFactory bn;
	BasePrint* testBN = bn.generatePrint(1);
	testBN->print();
}
