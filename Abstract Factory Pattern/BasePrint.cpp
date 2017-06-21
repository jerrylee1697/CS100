#include "BasePrint.h"
using namespace std;
#include <iostream>
#include <bitset>

BasePrint::BasePrint() {}

BasePrint::BasePrint(double value) {
	this->value = value;
}

//-----------------------------------------------------
//---------------Class: DoublePrint--------------------
//-----------------------------------------------------

// DoublePrint::DoublePrint(double value) : BasePrint(value) {}
DoublePrint::DoublePrint() {

}

DoublePrint::DoublePrint(double value) {
	this->value = value;
}

void DoublePrint::print() {
	cout << this->value << endl;
}

//-----------------------------------------------------
//------------------Class: HexPrint--------------------
//-----------------------------------------------------
HexPrint::HexPrint() {}

HexPrint::HexPrint(double value) {
	this->value = value;
}

void HexPrint::print() {
	int x = (int)value;
	cout << hex << x << endl;	
}

//-----------------------------------------------------
//---------------Class: BinaryPrint--------------------
//-----------------------------------------------------
BinaryPrint::BinaryPrint() {}

BinaryPrint::BinaryPrint(double value) {
	this->value = value;
}
void BinaryPrint::print() {
	int x = (int)value;
	bitset<8> bitset(value);
	for (unsigned i = 0; i < bitset.size(); ++i) {
		cout << bitset[i];
	}
	cout << endl;
}