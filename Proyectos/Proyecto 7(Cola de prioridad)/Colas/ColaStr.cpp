// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaStr.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ColaStr::ColaStr() {
	s = "";
}

bool ColaStr::vacia() {
	return s == "";
}

void ColaStr::poner(int e) {
	s = s + to_string(e) + "_";
}

void ColaStr::sacar(int &e) {
	if (!vacia()) {
		int pos = s.find_first_of("_"); // encontramos la posicion del _
		string ss = s.substr(0, pos); // sacamos el numero q toca
		e = atoi(ss.c_str()); // string --> char*
		s.erase(0, pos + 1); // borramos el que sacamos
	}
}

int ColaStr::primero() {
	if (!vacia()) {
		int pos = s.find_first_of("_"); // encontramos la posicion del _
		string ss = s.substr(0, pos); // sacamos el numero q toca
		return atoi(ss.c_str());
	}
}

string ColaStr::toStr() {
	ColaStr* aux = new ColaStr();
	string s = "<<";
	while (!vacia()) {
		int e;
		sacar(e);
		aux->poner(e);
		s = s + to_string(e);
		if (!vacia())
			s = s + ",";
	}
	s = s + "<<";
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		poner(e);
	}
	return s;
}
