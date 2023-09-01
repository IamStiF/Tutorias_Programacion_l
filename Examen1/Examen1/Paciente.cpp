#include "Paciente.h"

Paciente::Paciente(string nom, string ced, float pes, float alt, string gen, int anno): nombre(nom), id(ced), peso(pes), genero(gen), annoNaci(anno), estatura(alt), estado("no"), vac(NULL) {}
Paciente::~Paciente(){
	delete vac;
}


void Paciente::setEstado(string est) { estado = est; }
string Paciente::getNombre() { return nombre; }
string Paciente::getId() { return id; }
string Paciente::getGenero() { return genero; }
string Paciente::getEstado() { return estado; }

int Paciente::getNumSerie() { return vac->getNumSerie(); }
string Paciente::getCasa() { return vac->getCasa(); }

void Paciente::ingresaVacuna(Vacuna* ptrVac) {
	vac = ptrVac;
}

string Paciente::toString(){
	stringstream s;
	s << "\tPaciente:" << endl
		<< "Nombre: " << nombre << endl
		<< "Cedula: " << id << endl
		<< "Vacunado: " << estado << endl << endl;
	if (estado == "si") {
		s << vac->toString();
	}
	return s.str();
}
