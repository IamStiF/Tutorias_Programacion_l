#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Array
{
private:
	int* array1;
    int* array2;
	int tamN;
	int tamM;

public:
	Array(int, int);
	virtual ~Array();
	void orderBurbuja(int*, int);
	void ordenarArrays();
	void setArray1Value(int, int);
	void setArray2Value(int, int);
	string toString();
};

