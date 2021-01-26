#include <iostream>
#include "Menus.h"
#include "UMemoria.h";
#include "UConjuntoSm.h"
#include "UPoliSm.h"

using namespace std;

int main() {
	CSMemoria *m;
	ConjuntoSm *a;
	ConjuntoSm *b;
	ConjuntoSm *c;
	PoliSm *p;
	ConjuntoSm* aa = new ConjuntoSm();
	aa->inserta(1);
	aa->inserta(4);
	aa->inserta(5);
	aa->inserta(7);
	ConjuntoSm* com = aa->complemento(0, 20);
	cout << aa->toStr() << endl;
	cout << com->toStr() << endl;
	// lineas();
	// menu1(m, a, b, c, p);
	system("pause");
	return 0;
}
