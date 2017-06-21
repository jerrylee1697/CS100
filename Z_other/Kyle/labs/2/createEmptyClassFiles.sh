#!/bin/sh
touch $1.hh
touch $1.cc
echo $(cat kyle_861220581.txt) "
#include “./$1.hh”
$1::$1()
{}
$1::~$1()
{}" > $1.cc
echo $(cat kyle_861220581.txt) "
#ifndef $1_hh
#define $1_hh
class $1
{
public:
	$1();
	~$1();
private:
};
#endif" > $1.hh
