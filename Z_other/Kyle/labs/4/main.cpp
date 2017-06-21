////////////////////////////////////////////
//Composite & Strategy Patterns
//Lab 3 
//Lino Gonzalez Valdovinos and Kyle Semelka
// 1/30/2017
////////////////////////////////////////

#include <iostream>
#include "operations.h"
#include "Sort.h"
#include "Container.h"
#include "Decorators.h"

using namespace std;

void test1();

int main() {
    
    test1();
    cout << endl;
    
    Op* op3_4 = new Op(3.4);
    Op* op5_4 = new Op(-5.4);
    Op* op2_9 = new Op(2.7);
    Op* op2_1 = new Op(2.1);
    Mult* A = new Mult(op3_4, op5_4);
    cout<< A->evaluate()<<endl;
    Floor* fl = new Floor(A);
    cout<< fl->evaluate()<<endl;
    Mult* B = new Mult(fl,op2_1);
    cout<< B->evaluate()<<endl;
    Add* C= new Add(B,op2_9);
    cout<< C->evaluate()<<endl;
    Ceil* cl = new Ceil(C);
    cout<< cl->evaluate()<<endl;
    Abs* D = new Abs(cl);
    cout<< D->evaluate()<<endl;
    
    
    
};

void test1() {
     Op* op7 = new Op(7);
     Op* op4 = new Op(4);
     Op* op3 = new Op(3);
     Op* op2 = new Op(2);
     Mult* A = new Mult(op7, op4);
     Add* B = new Add(op3, A);
     Sub* C = new Sub(B, op2);
     Sqr* D = new Sqr(C);
     
     // Test VectorContainer
     VectorContainer* container1 = new VectorContainer();
     container1->add_element(A);
     container1->add_element(B);
     container1->add_element(C);
     container1->add_element(D);
     cout << "VectorContainer1 Before Sort: " << endl;
     container1->print();
     cout << "VectorContainer1 After SelectionSort: " << endl;
     container1->set_sort_function(new SelectionSort());
     container1->sort();
     container1->print();
     
     cout << endl;
     
     VectorContainer* container2 = new VectorContainer();
     container2->add_element(A);
     container2->add_element(B);
     container2->add_element(C);
     container2->add_element(D);
     cout << "VectorContainer2 Before Sort: " << endl;
     container2->print();
     cout << "VectorContainer2 After BubbleSort: " << endl;
     container2->set_sort_function(new BubbleSort());
     container2->sort();
     container2->print();

    cout << endl;
    
    // Test ListContainer
     ListContainer* container3 = new ListContainer();
     container3->add_element(A);
     container3->add_element(B);
     container3->add_element(C);
     container3->add_element(D);
     cout << "ListContainer3 Before Sort: " << endl;
     container3->print();
     cout << "ListContainer3 After SelectionSort: " << endl;
     container3->set_sort_function(new SelectionSort());
     container3->sort();
     container3->print();
     
     cout << endl;
     
     ListContainer* container4 = new ListContainer();
     container4->add_element(A);
     container4->add_element(B);
     container4->add_element(C);
     container4->add_element(D);
     cout << "ListContainer4 Before Sort: " << endl;
     container4->print();
     cout << "ListContainer4 After BubbleSort: " << endl;
     container4->set_sort_function(new BubbleSort());
     container4->sort();
     container4->print();
}