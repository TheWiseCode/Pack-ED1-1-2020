// ---------------------------------------------------------------------------

#ifndef ColaVector1H
#define ColaVector1H
// ---------------------------------------------------------------------------
#include<iostream>
#include<string>
#include "Funciones.h"
using namespace std;

const int maxV1 = 10;

class ColaV1 {
private:
	int* v;
	int ini, fin;

public:
	ColaV1();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	string toStr();
};
#endif
