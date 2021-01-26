// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UConjuntoLista.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ConjuntoLista::ConjuntoLista() {
	//lista = new ListaVector();
	lista = new ListaSm();
}

bool ConjuntoLista::vacio() {
	return lista->vacia();
}

int ConjuntoLista::cardinal() {
	return lista->longitud();
}

int ConjuntoLista::ordinal(int e) {
	int c = 0;
	int aux = lista->primero();
	while (aux != nulo) {
		c++; // empieza en 1
		if (lista->recupera(aux) == e) {
			return c;
		}
		aux = lista->siguiente(aux);
	}
	return -1;
}

void ConjuntoLista::inserta(int e) {
	if (!pertenece(e)) {
		lista->inserta(lista->primero(), e);
	}
}

void ConjuntoLista::suprime(int e) {
	if (pertenece(e)) {
		int nodo = lista->localiza(e);
		lista->suprime(nodo);
	}
}

bool ConjuntoLista::pertenece(int e) {
	int existe = lista->localiza(e);
	if (existe == nulo)
		return false;
	else
		return true;
}

int ConjuntoLista::muestrea() {
	if (!vacio()) {
		srand(time(NULL));
		int pos = rand() % cardinal();
		return elemento(pos);
	}
	else
		return 0;
}

int ConjuntoLista::elemento(int pos) {
	int c = 0;
	int aux = lista->primero();
	while (aux != nulo) {
		if (c == pos) {
			return lista->recupera(aux);
		}
		c++;
		aux = lista->siguiente(aux);
	}
	return 0;
}

void ConjuntoLista::reiniciar() {
	while (vacio() == false) {
		int r = muestrea();
		suprime(r);
	}
}

string ConjuntoLista::toStr() {
	// return lista->toStr();
	string r = "{";
	for (int i = 0; i < cardinal(); i++) {
		r += to_string(elemento(i));
		if (i < cardinal() - 1) {
			r += ",";
		}
	}
	r += "}";
	return r;
}

void ConjuntoLista::unir(ConjuntoLista *b, ConjuntoLista *c) {
	c->reiniciar();
	ConjuntoLista *aux = new ConjuntoLista();
	ConjuntoLista *a = this;
	// Para insertar a en c
	while (a->vacio() == false) {
		int r = a->muestrea();
		c->inserta(r);
		a->suprime(r);
		aux->inserta(r);
	}
	// Para recuperar los datos de a
	while (aux->vacio() == false) {
		int r = aux->muestrea();
		aux->suprime(r);
		a->inserta(r);
	}
	// Para insertar b en c
	while (b->vacio() == false) {
		int r = b->muestrea();
		c->inserta(r);
		b->suprime(r);
		aux->inserta(r);
	}
	// Para recuperar los datos de b
	while (aux->vacio() == false) {
		int r = aux->muestrea();
		aux->suprime(r);
		b->inserta(r);
	}
}

void ConjuntoLista::intersectar(ConjuntoLista *b, ConjuntoLista *c) {
	c->reiniciar();
	ConjuntoLista* a = this;
	ConjuntoLista* aux = new ConjuntoLista();
	// Inserto si el elemento pertenece a A y a B
	while (a->vacio() == false) {
		int r = a->muestrea();
		if (a->pertenece(r) && b->pertenece(r)) {
			c->inserta(r);
		}
		a->suprime(r);
		aux->inserta(r);
	}
	// Recupero los elementos de a
	while (aux->vacio() == false) {
		int r = aux->muestrea();
		aux->suprime(r);
		a->inserta(r);
	}
}
