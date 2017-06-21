#!/bin/sh
filename=$1
touch $filename.cc
touch $filename.hh

echo "#include “./$filename.hh”

$filename::$filename()
{}

$filename::~$filename()
{}" >> $filename.cc

echo "#ifndef $filename_hh
#define $filename_hh

class $filename
{
	public:
	$filename();
	~$filename();

	private:
};
#endif" >> $filename.hh
