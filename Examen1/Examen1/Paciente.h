#pragma once
#include"Vacuna.h"

class Paciente{
	private:
		string nombre; 
		string id; 
		float peso; 
		string genero; 
		int annoNaci;
		float estatura;
		string estado;
		Vacuna* vac;
	public:
		Paciente(string, string, float, float, string, int);
		virtual ~Paciente();

		void setEstado(string);
		string getNombre();
		string getId();
		string getGenero();
		string getEstado();
		string getCasa();
		int getNumSerie();

		void ingresaVacuna(Vacuna*);

		string toString();
};

