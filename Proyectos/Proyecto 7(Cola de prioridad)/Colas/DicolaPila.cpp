// ---------------------------------------------------------------------------

#pragma hdrstop

#include "DicolaPila.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

DicolaV::DicolaV() {
	K = new PilaVector();
}

void DicolaV::poner(int e) {
	PilaVector* aux = new PilaVector();
	while (!K->vacia()) {
		int s;
		K->sacar(s);
		aux->meter(s);
	}
	K->meter(e);
	while (!aux->vacia()) {
		int s;
		aux->sacar(s);
		K->meter(s);
	}
}

void DicolaV::Poner_Frente(int e) {
	K->meter(e);
}

void DicolaV::sacar(int& e) {
	if (!vacia()) {
		K->sacar(e);
	}
}

bool DicolaV::vacia() {
	return K->vacia();
}

int DicolaV::primero() {
	if (!vacia()) {
		return K->cima();
	}
}

string DicolaV::toStr() {
	DicolaV* aux = new DicolaV();
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
