// ---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaVector.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PilaVector::PilaVector() {
	elementos = new int[maxPila];
	tope = 0;
	c = 0;
}

bool PilaVector::vacia() {
	return tope == 0;
}

void PilaVector::meter(int e) {
	if (tope < maxPila) {
		elementos[tope] = e;
		tope++;
	}
}

void PilaVector::sacar(int &e) {
	if (!vacia()) {
		e = elementos[tope - 1];
		tope--;
	}
	else
		cout << "ERROR\n";
}

void PilaVector::meter1(int e) {
	if (c == 0) {
		elementos[0] = e;
		c++; // en realidad tope es un contador
	}
	else {
		for (int i = c; i > 0; i--) {
			elementos[i] = elementos[i - 1];
		}
		elementos[0] = e;
		c++;
	}
}

void PilaVector::sacar1(int &e) {
	if (c > 0) {
		e = elementos[0];
		for (int i = 0; i < c - 1; i++) {
			elementos[i] = elementos[i + 1];
		}
		c--;
	}
}

int PilaVector::sacar() {
	if (!vacia()) {
		int e = elementos[tope - 1];
		tope--;
		return e;
	}
	else
		cout << "ERROR\n";
}

int PilaVector::cima() {
	if (!vacia()) {
		return elementos[tope - 1];
	}
}

void PilaVector::mostrar() {
	PilaVector* aux = new PilaVector();
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

void PilaVector::mostrarVector() {
	for (int i = 0; i < c; i++) {
		cout << to_string(elementos[i]) << "   ";
	}
	cout << endl;
}
