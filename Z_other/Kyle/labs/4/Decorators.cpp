#include "Decorators.h"
#include <math.h>

Ceil::Ceil(Base* child){
        this->child = child;
}
double Ceil::evaluate(){
       return ceil(this->child->evaluate());
}
Floor::Floor(Base* child){
        this->child = child;
}
double Floor::evaluate(){
        return floor(this->child->evaluate());
}
Abs::Abs(Base* child){
        this->child = child;
}
double Abs::evaluate(){
        return abs(this->child->evaluate());
}
