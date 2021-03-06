// ---------------------------------------------------------------------------

#ifndef PilaPtrH
#define PilaPtrH
// ---------------------------------------------------------------------------
#include <iostream>

using namespace std;

struct NodoPila {
	int elemento;
	NodoPila* sig;
};

class PilaPtr {
private:
	NodoPila* tope;
	NodoPila* ptrPila;

public:
	PilaPtr();
	bool vacia();
	bool vacia1();
	void meter(int e);
	void sacar(int &e);
	void meter1(int e);
	void sacar1(int &e);
	int sacar();
	int cima();
	void mostrar();
	void mostrar1();
};

#endif
