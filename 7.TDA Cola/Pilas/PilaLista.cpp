// ---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaLista.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PilaLista::PilaLista() {
	l = new ListaVector();
}

bool PilaLista::vacia() {
	return l->vacia();
}

void PilaLista::meter(int e) {
	l->inserta(l->primero(), e);
}

void PilaLista::sacar(int &e) {
	if (!vacia()) {
		e = l->recupera(l->primero());
		l->suprime(l->primero());
	}
}

int PilaLista::sacar() {
	if (!vacia()) {
		int e = l->recupera(l->primero());
		l->suprime(l->primero());
		return e;
	}
}

int PilaLista::cima() {
	if (!vacia()) {
		return l->recupera(l->primero());
	}
}

void PilaLista::mostrar() {
	PilaLista* aux = new PilaLista();
	while (!vacia()) {
		int e;
		sacar1(e);
		aux->meter1(e);
		cout << e << endl;
	}
	while (!aux->vacia()) {
		int e;
		aux->sacar1(e);
		meter1(e);
	}
}

void PilaLista::meter1(int e) {
	if (vacia() == true) {
		l->inserta(l->fin(), e);
	}
	else {
		int ul = l->recupera(l->fin());
		l->inserta(l->fin(), ul);
		l->inserta(l->fin(), e);
		l->suprime(l->fin());
	}
}

void PilaLista::sacar1(int &e) {
	if (vacia() == false) {
		e = l->recupera(l->fin());
		l->suprime(l->fin());
	}
	else {
		cout << "ERROR,PILA VACIA" << endl;
	}
}

void PilaLista::mostrarLista() {
	cout << l->toStr() << endl;
}
