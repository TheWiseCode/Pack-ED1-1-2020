#include <iostream>
#include "MatrizVector.h"
#include "MatrizVectorCSR.h"
#include "MatrizPtr.h"
#include "MatrizPtrDb.h"
#include "MatrizSm.h"
#include "MatrizSmDb.h"
#include "UMemoria.h"

using namespace std;

int main() {
	// CSMemoria * mem = new CSMemoria();
	// mem->new_espacio("carlos,flores,perez");
	MatrizVector* m = new MatrizVector();
	m->dimensionar(5, 5);
	m->definir_valor_repetido(0);
	m->poner(1, 1, 10);
	m->poner(2, 2, 11);
	m->poner(2, 4, 14);
	m->poner(1, 3, 1);
	m->poner(1, 4, 1);
	m->poner(1, 5, 1);
	cout << m->toStr() << endl;
	m->definir_valor_repetido(1);
	cout << m->toStr() << endl;
	// cout << m->toStr() << endl;
	// mem->mostrar_memoria();
	system("pause");
	return 0;
}
