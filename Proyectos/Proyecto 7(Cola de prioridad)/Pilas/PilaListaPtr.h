// ---------------------------------------------------------------------------

#ifndef PilaListaPtrH
#define PilaListaPtrH
// ---------------------------------------------------------------------------
#include <iostream>
#include "ListaPtr.h"

using namespace std;

class PilaListaPtr {
private:
	ListaPtr *l;

public:
	PilaListaPtr();
	bool vacia();
	void meter(int e);
	void sacar(int &e);
	void meter1(int e);
	void sacar1(int &e);
	int sacar();
	int cima();
	void mostrar();
	void mostrarLista();
};
#endif
