#include <iostream>
#include "ConjuntoxyLista.h"

using namespace std;

int main() {
	ConjuntoxyLista* c = new ConjuntoxyLista();
	c->inserta(2, 2);
	c->inserta(2, 1);
	c->inserta(3, 6);
	c->inserta(10, 4);
	c->inserta(3, 6);
	cout << c->toStr() << endl;
	while (!c->vacio()) {
		int x, y;
		c->muestrea(x, y);
		c->suprime(x, y);
		cout << "X: " << x << " , Y: " << y << endl;
	}
	cout << c->toStr() << endl;
	system("pause");
	return 0;
}
