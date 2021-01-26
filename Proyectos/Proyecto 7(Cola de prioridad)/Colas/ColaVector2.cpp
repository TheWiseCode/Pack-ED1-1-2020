// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaVector2.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ColaV2::ColaV2() {
	v = new int[maxV2];
	ini = 0;
	fin = 0;
}

bool ColaV2::vacia() {
	return fin == 0;
}

void ColaV2::poner(int e) {
	if (fin < maxV2) {
		v[fin] = e;
		fin++;
	}
}

void ColaV2::sacar(int &e) {
	if (!vacia()) {
		e = v[0];
		// Desplazamiento
		for (int i = 0; i < fin - 1; i++) {
			v[i] = v[i + 1];
		}
		//
		fin--;
	}
}

int ColaV2::primero() {
	if (!vacia()) {
		return v[0];
	}
}

string ColaV2::toStr() {
	ColaV2* aux = new ColaV2();
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

int ColaV2::ultimo() {
	if (!vacia()) {
		return v[fin - 1];
	}
}

void ColaV2::sacar_final(int& e) {
	if (!vacia()) {
		e = v[fin - 1];
		fin--;
	}
}

void ColaV2::poner_frente(int e) {
	if (fin < maxV2) {
		for (int i = fin; i > 0; i--) {
			v[i] = v[i - 1];
		}
		v[0] = e;
		fin++;
	}
}
