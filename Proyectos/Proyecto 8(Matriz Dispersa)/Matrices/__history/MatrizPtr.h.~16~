// ---------------------------------------------------------------------------

#ifndef MatrizPtrH
#define MatrizPtrH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"

using namespace std;

// ---------------------------------------------------------------------------
struct NodoMat {
	int fil;
	int col;
	int dato;
	NodoMat* sig;
};

class MatrizPtr {
private:
	NodoMat* ptrMat;
	int df, dc;
	int rep;
	int nt;

	NodoMat* anterior(NodoMat* p);
	void suprime(NodoMat* p);
	NodoMat* existe(int f, int c);
	bool esValido(int rep);

public:
	MatrizPtr();
	void dimensionar(int f, int c);
	int dimension_fila();
	int dimension_columna();
	void poner(int f, int c, int valor);
	int elemento(int f, int c);
	void definir_valor_repetido(int r);
	float prom_elementos();
	float prom_elementos_validos();
	string toStr();
	void mostrar_atr();
};
#endif
