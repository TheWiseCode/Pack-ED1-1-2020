// ---------------------------------------------------------------------------

#ifndef PilaStrH
#define PilaStrH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <stdlib.h>//atoi
#include "Funciones.h"

using namespace std;

class PilaStr {
private:
	string k;

public:
	PilaStr();
	bool vacia();
	void meter(int e);
	void sacar(int &e);
	int cima();
	void mostrar();
};
#endif
