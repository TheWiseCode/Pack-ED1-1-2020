// ---------------------------------------------------------------------------

#ifndef ColadePrioridadH
#define ColadePrioridadH
// ---------------------------------------------------------------------------
#include<iostream>
#include<string>
#include "ColaSm.h"
#include "Funciones.h"
#include "UMemoria.h"

using namespace std;

const int maxCP = 3;

class ColadePrioridad {
private:
	ColaSm** vc;//* hace referencia a que va a ser un vector
	//otro * hace referencia a que los elementos del vector van a ser punteros
	int* vf;
	int colaActual;
	int cant;

public:
	ColadePrioridad();
	ColadePrioridad(CSMemoria* m);
	bool vacia();
	int primero();
	void primero(int &e);
	void poner(int e, int prior);
	void frecuencia_prioridad(int f, int p);
	void sacar(int& e);
	string toStr();
};
#endif
