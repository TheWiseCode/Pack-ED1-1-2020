// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaLista.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ColaLista::ColaLista() {
	L = new ListaPtr();
}

bool ColaLista::vacia() {
	return L->vacia();
}

void ColaLista::poner(int e) {
	if (vacia()) {
		L->inserta(L->fin(), e);
	}
	else {
		int ul = L->recupera(L->fin());
		L->inserta(L->fin(), ul);
		L->modifica(L->fin(), e);
	}
}

void ColaLista::sacar(int &e) {
	if (!vacia()) {
		e = L->recupera(L->primero());
		L->suprime(L->primero());
	}
}

void ColaLista::poner1(int e) { // Metodos del ingeniero
	L->inserta(L->primero(), e);
}

void ColaLista::poner_frente1(int e) { // Metodos del ingeniero
	int p = L->recupera(L->fin());
	L->inserta(L->fin(), e);
	L->suprime(L->fin());
	L->inserta(L->fin(), p);
}

void ColaLista::sacar1(int &e) { // Metodos del ingeniero
	if (!vacia()) {
		e = L->recupera(L->fin());
		L->suprime(L->fin());
	}
}

int ColaLista::primero() {
	if (!vacia()) {
		return L->recupera(L->primero());
	}
}

string ColaLista::toStr() {
	ColaLista* aux = new ColaLista();
	string s = "<<";
	while (!vacia()) {
		int e;
		sacar1(e);
		aux->poner1(e);
		s = s + to_string(e);
		if (!vacia())
			s = s + ",";
	}
	s = s + "<<";
	while (!aux->vacia()) {
		int e;
		aux->sacar1(e);
		poner1(e);
	}
	return s;
}

int ColaLista::ultimo() {
	if (!vacia()) {
		return L->recupera(L->fin());
	}
}

void ColaLista::sacar_final(int& e) {
	if (!vacia()) {
		e = L->recupera(L->fin());
		L->suprime(L->fin());
	}
}

void ColaLista::poner_frente(int e) {
	L->inserta(L->primero(), e);
}
