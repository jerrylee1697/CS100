////////////////////////////////////////////
//Composite & Strategy Patterns
//Lab 3 
//Lino Gonzalez Valdovinos and Kyle Semelka
// 1/30/2017
////////////////////////////////////////

#include <cmath>
#include <iostream>
#include "operations.h"
using namespace std;

int main() {
    // Base* tree1 = new Mult(new Sub(new Add(new Op(15), new Op(20)), new Op(25)), new Op(10));
    // Base* tree2 = new Sub(new Add(new Op(3), new Mult(new Op(7), new Op(4))), new Op(2));
    // cout << tree1->evaluate() << endl;
    // cout << tree2->evaluate() << endl;
    
    // Base* exampleTree = new Sub();
    // exampleTree->addChilds(new Add(), new Op(2));
    // exampleTree->leftChild->addChilds(new Op(3), new Op(4)));
    // exampleTree->leftChild->addChilds(new Op(7), new Op(4));
    // cout << exampleTree->evaluate() << endl;
    Op* op0=new Op(0);


    Op* op2 = new Op(2);
    Op* op3 = new Op(3);
    Op* op7 = new Op(7);
    Op* op4 = new Op(4);
    Mult* A = new Mult(op7, op4);
    Add* B = new Add(op3, A);
    Sub* C = new Sub(B, op2);
    Sqr* D = new Sqr(C);
    cout << D->evaluate() << endl;
    
    Div* Z = new Div (op0,D);
    cout << Z->evaluate() << endl;
    
};
