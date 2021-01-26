// ---------------------------------------------------------------------------

#ifndef DicolaColaH
#define DicolaColaH
// ---------------------------------------------------------------------------
#include<iostream>
#include<string>
#include "Funciones.h"
#include "ColaPtr.h"
using namespace std;

class DicolaC {
private:
	ColaPtr* k;

public:
	DicolaC();
	void poner(int e);
	void poner_frente(int e);
	void sacar(int& e);
	bool vacia();
	int primero();
	string toStr();
};
#endif
