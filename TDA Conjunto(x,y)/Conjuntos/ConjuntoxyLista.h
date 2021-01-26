// ---------------------------------------------------------------------------

#ifndef ConjuntoxyListaH
#define ConjuntoxyListaH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include "ListaPtr.h"

using namespace std;

class ConjuntoxyLista {
private:
	ListaPtr *lista;

public:
	ConjuntoxyLista();
	bool vacio();
	int cardinal();
	int ordinal(int x, int y);
	void inserta(int x, int y);
	void suprime(int x, int y);
	bool pertenece(int x, int y);
	void elemento(int &x, int &y, int pos);
	void muestrea(int &x, int &y);
	string toStr();
};
#endif
