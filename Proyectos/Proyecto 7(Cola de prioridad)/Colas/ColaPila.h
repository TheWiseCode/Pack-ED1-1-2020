// ---------------------------------------------------------------------------

#ifndef ColaPilaH
#define ColaPilaH
// ---------------------------------------------------------------------------
#include<iostream>
#include<string>
#include "Funciones.h"
#include "PilaPtr.h"

using namespace std;

class ColaPila {
private:
	PilaPtr* p;

public:
	ColaPila();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	string toStr();

};
#endif
