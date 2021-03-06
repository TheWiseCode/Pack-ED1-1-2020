// ---------------------------------------------------------------------------

#pragma hdrstop

#include "DicolaCola.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

DicolaC::DicolaC() {
	k = new ColaPtr();
}

void DicolaC::poner(int e) {
	k->poner(e);
}

void DicolaC::poner_frente(int e) {
	ColaPtr* aux = new ColaPtr();
	while (!k->vacia()) {
		int s;
		k->sacar(s);
		aux->poner(s);
	}
	k->poner(e);
	while (!aux->vacia()) {
		int s;
		aux->sacar(s);
		k->poner(s);
	}
}

void DicolaC::sacar(int& e) {
	k->sacar(e);
}

bool DicolaC::vacia() {
	return k->vacia();
}

int DicolaC::primero() {
	return k->primero();
}

string DicolaC::toStr() {
	DicolaC* aux = new DicolaC();
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
