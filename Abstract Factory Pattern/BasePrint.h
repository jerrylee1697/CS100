#ifndef BASEPRINT_H
#define BASEPRINT_H

class BasePrint {
	protected:
		/* Value to Print */
		double value;

	public:
		/* Constructors */
		BasePrint();
		BasePrint(double value);
		
		/* Pure Virtual Print Function */
		virtual void print() = 0;
};

class DoublePrint : public BasePrint {
	public:
		/* Constructors */
		DoublePrint();
		DoublePrint(double value);
		
		/* Pure Virtual Print Function */
		void print();
};

class HexPrint : public BasePrint {
	public:
		HexPrint();
		HexPrint(double value);

		void print();
};

class BinaryPrint : public BasePrint {
	public:
		BinaryPrint();
		BinaryPrint(double value);

		void print();
};

#endif