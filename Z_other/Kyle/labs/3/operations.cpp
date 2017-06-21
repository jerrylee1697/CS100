#include <cmath>
#include <iostream>
#include <cmath>
#include "operations.h"

// Base::Base() : { }

// Base::addChilds()

//methods for Op class
Op::Op(){
    value=0;
}
Op::Op(double value){
    this->value = value;
}

void Op::set(double val) {
    value=val;
}
double Op::evaluate(){
    return value;
}

void Op::addChilds(Base* newChild, Base* b)  { 
    
}

//methods for Mult class
Mult::Mult(){
    
}

Mult::Mult(Base* newLeftChild, Base* newRightChild) {
    this->leftChild = newLeftChild;
    this->rightChild = newRightChild;
}

double Mult::evaluate(){
    return (rightChild->evaluate() * leftChild->evaluate());
}
void Mult::addChilds(Base* newLeftChild, Base* newRightChild){
    this->leftChild=newLeftChild;
    this->rightChild=newRightChild;
}

//methods for Div class 
Div::Div(){
    
    
}
Div::Div(Base* newLeftChild, Base* newRightChild) {
    this->leftChild = newLeftChild;
    this->rightChild = newRightChild;
}

double Div::evaluate(){
    
    if (leftChild->evaluate()==0){
        
        exit(1);
    }
    else{
        return (rightChild->evaluate() / leftChild->evaluate());
    }
}

void Div::addChilds(Base* newLeftChild, Base* newRightChild) {
    this->leftChild = newLeftChild;
    this->rightChild = newRightChild;
}

//methods for Add class
Add::Add(){
    
    
}

Add::Add(Base* newLeftChild, Base* newRightChild) {
    this->leftChild = (newLeftChild);
    this->rightChild = (newRightChild);
}

void Add::addChilds(Base* newLeftChild, Base* newRightChild) {
    this->leftChild = newLeftChild;
    this->rightChild = newRightChild;
}

double Add::evaluate(){
    return (rightChild->evaluate() + leftChild->evaluate());
}

//methods for Sub class
Sub::Sub(){
    
}

Sub::Sub(Base* newLeftChild, Base* newRightChild) {
    this->leftChild = newLeftChild;
    this->rightChild = newRightChild;
}

double Sub::evaluate(){
    return (leftChild->evaluate() - rightChild->evaluate());
}

void Sub::addChilds(Base* newLeftChild, Base* newRightChild) {
    this->leftChild = newLeftChild;
    this->rightChild = newRightChild;
}

//methods for Sqr class
Sqr::Sqr(){
    
}
Sqr::Sqr(Base* newChild) {
   this->child = newChild;
}
void Sqr::addChilds(Base * child){
    this->child = child;
}
void Sqr::addChilds(Base * child, Base* child2){
    
}
double Sqr::evaluate(){
    return pow(child->evaluate(), 2);
}