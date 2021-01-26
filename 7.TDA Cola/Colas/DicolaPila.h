// ---------------------------------------------------------------------------

#ifndef DicolaPilaH
#define DicolaPilaH
// ---------------------------------------------------------------------------
#include<iostream>
#include<string>
#include "Funciones.h"
#include "PilaVector.h"
using namespace std;

class DicolaV {
private:
	PilaVector* K;

public:
	DicolaV();
	void poner(int);
	void Poner_Frente(int);
	void sacar(int&);
	bool vacia();
	int primero();
	string toStr();
};
#endif
