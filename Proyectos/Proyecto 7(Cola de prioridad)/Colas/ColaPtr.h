// ---------------------------------------------------------------------------

#ifndef ColaPtrH
#define ColaPtrH
// ---------------------------------------------------------------------------
#include<iostream>
#include<string>
#include "Funciones.h"
using namespace std;

struct NodoCola {
	int elemento;
	NodoCola* sig;
};

typedef NodoCola* direccion;

class ColaPtr {
private:
	direccion ini;
	direccion fin;

public:
	ColaPtr();
	bool vacia();
	void poner(int e);
	void poner1(int e);
	void sacar(int &e);
	void sacar1(int &e);
	int primero();
	string toStr();
	void mostrar();
	// Metodos de dicola
	int ultimo();
	void sacar_final(int& e);
	void poner_frente(int e);
};
#endif
