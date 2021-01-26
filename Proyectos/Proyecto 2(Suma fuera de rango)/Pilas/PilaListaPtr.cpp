// ---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaListaPtr.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PilaListaPtr::PilaListaPtr() {
	l = new ListaPtr();
}

bool PilaListaPtr::vacia() {
	return l->vacia();
}

void PilaListaPtr::meter(int e) {
	l->inserta(l->primero(), e);
}

void PilaListaPtr::sacar(int &e) {
	if (!vacia()) {
		e = l->recupera(l->primero());
		l->suprime(l->primero());
	}
}

void PilaListaPtr::meter1(int e) {
	if (vacia()) {
		l->inserta(l->fin(), e);
	}
	else {
		int ul = l->recupera(l->fin());
		l->inserta(l->fin(), ul);
		l->modifica(l->fin(), e);
	}
}

void PilaListaPtr::sacar1(int &e) {
	if (!vacia()) {
		e = l->recupera(l->fin());
		l->suprime(l->fin());
	}
}

int PilaListaPtr::sacar() {
	if (!vacia()) {
		int e = l->recupera(l->primero());
		l->suprime(l->primero());
		return e;
	}
}

int PilaListaPtr::cima() {
	if (!vacia()) {
		return l->recupera(l->primero());
	}
}

void PilaListaPtr::mostrar() {
	PilaListaPtr* aux = new PilaListaPtr();
	while (!vacia()) {
		int e;
		sacar(e);
		aux->meter(e);
		cout << e << endl;
	}
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		meter(e);
	}
}

void PilaListaPtr::mostrarLista() {
	cout << l->toStr() << endl;
}
