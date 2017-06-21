#include <iostream>
using namespace std;
#include "BasePrint.h"

int main() {
	DoublePrint* db = new DoublePrint(11.6);
	HexPrint* hexp = new HexPrint(11.6);
	BasePrint* bin = new BinaryPrint(1);

	db->print();
	hexp->print();
	bin->print();

	
}