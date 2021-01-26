// ---------------------------------------------------------------------------

#ifndef ListaPtrH
#define ListaPtrH

// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"

using namespace std;

struct NodoL {
	int elemento;
	NodoL* sig;
};

class ListaPtr {
private:
	NodoL* ptrElementos;
	int longi;

	void intercambio(NodoL*, NodoL*);

public:
	ListaPtr();
	// Funciones de direccion
	NodoL* fin();
	NodoL* primero();
	NodoL* siguiente(NodoL*);
	NodoL* anterior(NodoL*);
	// Selector
	int recupera(NodoL*);
	// modificadores
	void inserta(NodoL*, int);
	void inserta_inicio(int);
	void inserta_fin(int);
	void suprime(NodoL*);
	void modifica(NodoL*, int);
	//
	bool vacia();
	int longitud();
	string toStr();
	//
	NodoL* localiza(int);
	void elimina_dato(int);
	void anula();
	void muestra_nodos();
	// Ejercicios tipo examen
	bool es_palindroma();
	void inserta(int, int);
	void elimina_nodo_con_mayor_dato();
	ListaPtr *sin_repetidos_ptr();
	ListaPtr sin_repetidos();
	void ordenamiento();
	NodoL* nodoEnPosicion(int k);
};
#endif
