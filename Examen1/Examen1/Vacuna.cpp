#include "Vacuna.h"

Vacuna::Vacuna(string cas, int numL, int numS, string fechaV, string fechaA): casa(cas), numLote(numL), numSerie(numS), fechaVen(fechaV), fechaApli(fechaA){}
Vacuna::~Vacuna(){}

string Vacuna::getCasa() { return casa; }
int Vacuna::getNumSerie() { return numSerie; }

string Vacuna::toString(){
	stringstream s;
	s << "\tVacuna:" << endl
		<< "Casa Comercial: " << casa << endl
		<< "Numero de lote: " << numLote << endl
		<< "Numero de serie: " << numSerie << endl
		<< "Fecha de vencimiento: " << fechaVen << endl
		<< "Fecha de aplicacion: " << fechaApli << endl << endl;
	return s.str();
}
