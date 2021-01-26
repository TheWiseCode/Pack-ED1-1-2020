//---------------------------------------------------------------------------

#ifndef ColadePrioridadH
#define ColadePrioridadH
//---------------------------------------------------------------------------
#include<iostream>
#include<string>
#include "ColaPtr.h"
#include "Funciones.h"

using namespace std;

const int maxCP = 3;

class ColadePrioridad{
	private:
		ColaPtr* vc;
		int* vf;
		int colaActual;
		int cant;
	public:
		ColadePrioridad();
		bool vacia();
		int primero();
		void poner(int e,int prior);
		void frecuencia_prioridad(int f,int p);
		void sacar(int& e);
		string toStr();
};
#endif
