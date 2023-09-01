#pragma once
#include"Paciente.h"

class Coleccion{
	private:
		Paciente* vecPac[5000];
		Paciente* vecVac[5000];
		int canP;
		int canV;
		int tamP;
		int tamV;
	public:
		Coleccion();
		virtual ~Coleccion();
		
		int getCanP();
		int getCanV();

		bool ingresaPaciente(Paciente*);
		bool ponerVacuna(Vacuna*, string);

		bool estaNombre(string);
		bool estaId(string);
		bool estaVacunado(string);
		bool estaVacuna(int);
		bool estaCasa(string);

		string buscaPac(string);
		float porceVacu();

		string listaPac();
		string listaVac();
		string listaVacXCasa(string);
};

