#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class Vacuna{
	private:
		string casa; 
		int numLote; 
		int numSerie;  
		string fechaVen; 
		string fechaApli;
	public:
		Vacuna(string, int, int, string, string);
		virtual ~Vacuna();

		string getCasa();
		int getNumSerie();

		string toString();
};

