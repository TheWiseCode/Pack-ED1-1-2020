// ---------------------------------------------------------------------------

#ifndef ColaSmH
#define ColaSmH
// ---------------------------------------------------------------------------
#include<iostream>
#include<string>
#include "Funciones.h"
#include "UMemoria.h"
using namespace std;

const string elementoC = "->elemento";
const string sigC = "->sig";
const string datosC = "elemento,sig";

typedef int direccion1;

class ColaSm {
private:
	CSMemoria* mem;
	direccion1 ini;
	direccion1 fin;

public:
	ColaSm();
	ColaSm(CSMemoria* m);
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	string toStr();
	// Metodos de dicola
	int ultimo();
	void sacar_final(int& e);
	void poner_frente(int e);
};

#endif
