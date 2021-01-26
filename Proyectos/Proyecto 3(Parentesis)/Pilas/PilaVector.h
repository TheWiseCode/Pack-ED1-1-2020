// ---------------------------------------------------------------------------

#ifndef PilaVectorH
#define PilaVectorH
// ---------------------------------------------------------------------------
#include <iostream>
#include "Funciones.h"

using namespace std;

const int maxPila = 100;

class PilaVector {
private:
	int* elementos;
	int tope;
	int c;

public:
	PilaVector();
	bool vacia();
	void meter(int e);
	void sacar(int &e);
	void meter1(int e);
	void sacar1(int &e);
	int sacar();
	int cima();
	void mostrar();
	void mostrarVector();
};
#endif
