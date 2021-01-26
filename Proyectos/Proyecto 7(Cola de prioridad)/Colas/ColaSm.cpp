// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaSm.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ColaSm::ColaSm() {
	mem = new CSMemoria();
	ini = nulo;
	fin = nulo;
}

ColaSm::ColaSm(CSMemoria* m) {
	mem = m;
	ini = nulo;
	fin = nulo;
}

bool ColaSm::vacia() {
	return ini == nulo;
}

void ColaSm::poner(int e) {
	direccion1 aux = mem->new_espacio(datosC);
	if (aux != nulo) {
		mem->poner_dato(aux, elementoC, e); // aux->elemento = e;
		mem->poner_dato(aux, sigC, nulo); // aux->sig = NULL;
		if (vacia()) {
			ini = aux;
			fin = aux;
		}
		else {
			mem->poner_dato(fin, sigC, aux); // fin->sig = aux;
			fin = aux;
		}
	}
}

void ColaSm::sacar(int &e) {
	if (!vacia()) {
		e = mem->obtener_dato(ini, elementoC); // ini->elemento;
		direccion1 x = ini;
		if (ini == fin) {
			ini = nulo;
			fin = nulo;
		}
		else {
			ini = mem->obtener_dato(ini, sigC); // ini->sig;
		}
		mem->delete_espacio(x);
	}
}

int ColaSm::primero() {
	if (!vacia()) {
		return mem->obtener_dato(ini, elementoC); // ini->elemento;
	}
}

string ColaSm::toStr() {
	ColaSm* aux = new ColaSm();
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

int ColaSm::ultimo() {
	if (!vacia()) {
		return mem->obtener_dato(fin, elementoC); // fin->elemento;
	}
}

void ColaSm::sacar_final(int& e) {
	if (!vacia()) {
		e = mem->obtener_dato(fin, elementoC); // fin->elemento;
		direccion1 del = fin;
		if (ini == fin) {
			ini = nulo;
			fin = nulo;
		}
		else {
			direccion1 aux = ini;
			while (mem->obtener_dato(aux, sigC) != fin) { // aux->sig
				aux = mem->obtener_dato(aux, sigC); // aux->sig
			}
			fin = aux;
			mem->poner_dato(fin, sigC, nulo); // fin->sig = NULL;
		}
		mem->delete_espacio(del); // delete(del);
	}
}

void ColaSm::poner_frente(int e) {
	direccion1 aux = mem->new_espacio(datosC); // new NodoCola;
	if (aux != nulo) {
		mem->poner_dato(aux, elementoC, e); // aux->elemento = e;
		mem->poner_dato(aux, sigC, nulo); // aux->sig = NULL;
		if (vacia()) {
			ini = aux;
			fin = aux;
		}
		else {
			mem->poner_dato(aux, sigC, ini); // aux->sig = ini;
			ini = aux;
		}
	}
}
