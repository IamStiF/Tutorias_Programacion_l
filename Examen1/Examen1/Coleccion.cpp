#include "Coleccion.h"

Coleccion::Coleccion(){
	canP = 0;
	canV = 0;
	tamP = 5000;
	tamV = 5000;
	for (int i = 0; i < tamP; i++) {
		vecPac[i] = NULL;
		vecVac[i] = NULL;
	}
}

Coleccion::~Coleccion(){
	for (int i = 0; i < canP; i++) {
		delete vecPac[i];
	}
	for (int i = canV; i > 0; i--) {
		delete vecVac[i];
	}
}

int Coleccion::getCanP() { return canP; }
int Coleccion::getCanV() { return canV; }

bool Coleccion::ingresaPaciente(Paciente* ptrPaci){
	if (canP < tamP) {
		vecPac[canP++] = ptrPaci;
		return true;
	}
	return false;
}

bool Coleccion::ponerVacuna(Vacuna* ptrVac, string id) {
	for (int i = 0; i < canP; i++) {
		if (vecPac[i]->getId() == id) {
			vecPac[i]->ingresaVacuna(ptrVac);
			if (canV < tamV) {
				vecVac[canV] = vecPac[i];
				vecVac[canV]->setEstado("si");
				canV++;
			}
			return true;
		}
	}
	return false;
}

bool Coleccion::estaNombre(string nombre) {
	for (int i = 0; i < canP; i++) {
		if (vecPac[i]->getNombre() == nombre) {
			return true;
		}
	}
	return false;
}
bool Coleccion::estaId(string ced){
	for (int i = 0; i < canP; i++) {
		if (vecPac[i]->getId() == ced) {
			return true;
		}
	}
	return false;
}
bool Coleccion::estaVacunado(string ced){
	for (int i = 0; i < canV; i++) {
		if (vecVac[i]->getId() == ced) {
			return true;
		}
	}
	return false;
}
bool Coleccion::estaVacuna(int numS){
	for (int i = 0; i < canV; i++) {
		if (vecVac[i]->getNumSerie() == numS) {
			return true;
		}
	}
	return false;
}

bool Coleccion::estaCasa(string cas) {
	for (int i = 0; i < canV; i++) {
		if (vecVac[i]->getCasa() == cas) {
			return true;
		}
	}
	return false;

}

string Coleccion::buscaPac(string ced) {
	stringstream s;
	for (int i = 0; i < canP; i++) {
		if (vecPac[i]->getId() == ced) {
			s << vecPac[i]->toString();
		}
	}
	return s.str();
}

float Coleccion::porceVacu() { return (canV / canP) * 100; }

string Coleccion::listaPac() {
	stringstream s;
	s << "\tLista de pacientes:" << endl << endl;
	for (int i = 0; i < canP; i++) {
		s << vecPac[i]->toString();
	}
	return s.str();
}

string Coleccion::listaVac() {
	stringstream s;
	s << "\tLista de vacunados por genero:" << endl << endl
	  << "\t--------Mujeres--------" << endl << endl;
	for (int i = 0; i < canV; i++) {
		if (vecVac[i]->getGenero() == "mujer") {
			s << "Nombre: " << vecVac[i]->getNombre() << endl
			  << "Cedula: " << vecVac[i]->getId() << endl << endl;
		}
	}
	s << "\t--------Hombres--------" << endl << endl;
	for (int i = 0; i < canV; i++) {
		if (vecVac[i]->getGenero() == "hombre") {
			s << "Nombre: " << vecVac[i]->getNombre() << endl
			  << "Cedula: " << vecVac[i]->getId() << endl << endl;
		}
	}
	return s.str();
}

string Coleccion::listaVacXCasa(string cas) {
	stringstream s;
	for (int i = 0; i < canV; i++) {
		if (vecVac[i]->getCasa() == cas) {
			s << "Nombre: " << vecVac[i]->getNombre() << endl
			  << "Cedula: " << vecVac[i]->getId() << endl <<endl;
		}
	}
	return s.str();
}