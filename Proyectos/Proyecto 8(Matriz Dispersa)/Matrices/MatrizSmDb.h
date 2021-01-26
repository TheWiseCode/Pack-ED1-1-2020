// ---------------------------------------------------------------------------

#ifndef MatrizSmDbH
#define MatrizSmDbH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include "UMemoria.h"

using namespace std;

const string dataCol = "col,dato,sigC";
const string colSm = "->col";
const string datoSm = "->dato";
const string sigC = "->sigC";

const string dataFil = "fil,sigF,antF,ptrCol";
const string filSm = "->fil";
const string sigF = "->sigF";
const string antF = "->antF";
const string ptrCol = "->ptrCol";

class MatrizSmDb {
private:
	CSMemoria *mem;
	int ptrMat;
	int df, dc;
	int rep;
	int nt;

	void insertar_fila(int nf);
	void insertar_col(int nf, int nc);
	int existe_fil(int f);
	int existe_col(int f, int c);
	int anterior(int nf, int p);
	void suprime(int nf, int p);

public:
	MatrizSmDb();
	MatrizSmDb(CSMemoria *m);
	void dimensionar(int f, int c);
	int dimension_fila();
	int dimension_columna();
	void poner(int f, int c, int valor);
	int elemento(int f, int c);
	void definir_valor_repetido(int r);
	string toStr();
};
#endif
