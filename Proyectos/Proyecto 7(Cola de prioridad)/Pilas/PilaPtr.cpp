// ---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaPtr.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PilaPtr::PilaPtr() {
	tope = NULL;
	ptrPila = NULL;
}

bool PilaPtr::vacia() {
	return tope == NULL;
}

bool PilaPtr::vacia1() {
	return ptrPila == NULL;
}

void PilaPtr::meter(int e) {
	NodoPila* aux = new NodoPila;
	if (aux != NULL) {
		aux->elemento = e;
		aux->sig = tope;
		tope = aux;
	}
}

void PilaPtr::sacar(int &e) {
	if (!vacia()) {
		e = tope->elemento;
		NodoPila* sup = tope;
		tope = tope->sig;
		delete(sup);
	}
}

int PilaPtr::sacar() {
	if (!vacia()) {
		int e = tope->elemento;
		NodoPila* sup = tope;
		tope = tope->sig;
		delete(sup);
		return e;
	}
}

int PilaPtr::cima() {
	if (!vacia()) {
		return tope->elemento;
	}
}

void PilaPtr::mostrar() {
	PilaPtr* aux = new PilaPtr();
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

void PilaPtr::mostrar1() {
	PilaPtr* aux = new PilaPtr();
	while (!vacia1()) {
		int e;
		sacar1(e);
		aux->meter1(e);
		cout << e << endl;
	}
	while (!aux->vacia1()) {
		int e;
		aux->sacar1(e);
		meter1(e);
	}
}

void PilaPtr::meter1(int e) {
	if (ptrPila == NULL) { // vacia()
		NodoPila* nuevo = new NodoPila;
		nuevo->elemento = e;
		nuevo->sig = NULL;
		ptrPila = nuevo;
	}
	else {
		NodoPila* nuevo = new NodoPila;
		nuevo->elemento = e;
		nuevo->sig = NULL;
		NodoPila* aux = ptrPila;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

void PilaPtr::sacar1(int &e) {
	if (ptrPila != NULL) {
		if (ptrPila->sig == NULL) {
			e = ptrPila->elemento;
			delete(ptrPila);
			ptrPila = NULL;
		}
		else {
			NodoPila* aux = ptrPila;
			NodoPila* ant;
			while (aux->sig != NULL) {
				ant = aux;
				aux = aux->sig;
			}
			e = aux->elemento;
			ant->sig = NULL;
			delete(aux);
		}
	}
}