// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaVector1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ColaV1::ColaV1() {
	v = new int[maxV1];
	ini = 0;
	fin = 0;
}

bool ColaV1::vacia() {
	return ini == fin;
}

void ColaV1::poner(int e) {
	if (fin < maxV1) {
		v[fin] = e;
		fin++;
	}
}

void ColaV1::sacar(int &e) {
	if (!vacia()) {
		e = v[ini];
		ini++;
	}
}

int ColaV1::primero() {
	if (!vacia()) {
		return v[ini];
	}
}

string ColaV1::toStr() {
	string s = "<<";
	for (int i = ini; i < fin; i++) {
		s += to_string(v[i]);
		if (i < fin - 1)
			s += ",";
	}
	s += "<<";
	return s;
}
