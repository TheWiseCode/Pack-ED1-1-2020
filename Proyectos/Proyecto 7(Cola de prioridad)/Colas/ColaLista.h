// ---------------------------------------------------------------------------

#ifndef ColaListaH
#define ColaListaH
// ---------------------------------------------------------------------------
#include<iostream>
#include<string>
#include "ListaPtr.h"
#include "Funciones.h"
using namespace std;

class ColaLista {
private:
	ListaPtr* L;

public:
	ColaLista();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	void poner1(int e);
	void poner_frente1(int e);
	void sacar1(int &e);
	int primero();
	string toStr();
	// Metodos de dicola
	int ultimo();
	void sacar_final(int& e);
	void poner_frente(int e);
};
#endif
