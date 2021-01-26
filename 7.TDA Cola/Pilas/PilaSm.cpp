// ---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaSm.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PilaSm::PilaSm() {
	mem = new CSMemoria();
	tope = nulo; // nulo = -1
}

PilaSm::PilaSm(CSMemoria* m) {
	mem = m;
	tope = nulo;
}

bool PilaSm::vacia() {
	return tope == nulo;
}

void PilaSm::meter(int e) {
	int aux = mem->new_espacio(datosP);
	if (aux != nulo) {
		mem->poner_dato(aux, elementoP, e); // aux->elemento = e;
		mem->poner_dato(aux, sigP, tope); // aux->sig = tope;
		tope = aux;
	}
}

void PilaSm::sacar(int &e) {
	if (!vacia()) {
		e = mem->obtener_dato(tope, elementoP); // tope->elemento;
		int sup = tope;
		tope = mem->obtener_dato(tope, sigP); // tope->sig;
		mem->delete_espacio(sup); // delete(sup);
	}
}

int PilaSm::sacar() {
	if (!vacia()) {
		int e = mem->obtener_dato(tope, elementoP); // tope->elemento;
		int sup = tope;
		tope = mem->obtener_dato(tope, sigP); // tope->sig;
		mem->delete_espacio(sup); // delete(sup);
		return e;
	}
}

int PilaSm::cima() {
	if (!vacia()) {
		return mem->obtener_dato(tope, elementoP); // tope->elemento;
	}
}

void PilaSm::mostrar() {
	PilaSm* aux = new PilaSm();
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
