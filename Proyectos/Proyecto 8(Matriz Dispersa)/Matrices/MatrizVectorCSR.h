//---------------------------------------------------------------------------

#ifndef MatrizVectorCSRH
#define MatrizVectorCSRH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"

using namespace std;
// ---------------------------------------------------------------------------
class MatrizVectorCSR {
private:
	int *vf;
	int *vc;
	int *vd;
	int df, dc;
	int rep;
	int nt;

	int posicion_insertar(int f);
	int posicion(int f,int c);
public:
	MatrizVectorCSR();
	void dimensionar(int f, int c);
	int dimension_fila();
	int dimension_columna();
	void poner(int f,int c,int valor);
	int elemento(int f,int c);
	void definir_valor_repetido(int r);
	int numero_casillas_validas();
	string toStr();

};
#endif
