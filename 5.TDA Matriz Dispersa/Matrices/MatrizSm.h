// ---------------------------------------------------------------------------

#ifndef MatrizSmH
#define MatrizSmH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include "UMemoria.h"

using namespace std;

// ---------------------------------------------------------------------------
const string dataM = "fil,col,dato,sig";
const string filM = "->fil";
const string colM = "->col";
const string datoM = "->dato";
const string sigM = "->sig";

class MatrizSm {
private:
	CSMemoria *mem;
	int ptrMat;
	int df, dc;
	int rep;
	int nt;

	int anterior(int p);
	void suprime(int p);
	int existe(int f, int c);

public:
	MatrizSm();
	MatrizSm(CSMemoria* m);
	void dimensionar(int f, int c);
	int dimension_fila();
	int dimension_columna();
	void poner(int f, int c, int valor);
	int elemento(int f, int c);
	void definir_valor_repetido(int r);
	string toStr();
};
#endif
