// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UConjuntoPtr.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ConjuntoPtr::ConjuntoPtr() {
	cant = 0;
	ptrConj = NULL;
}

bool ConjuntoPtr::vacio() {
	return cant == 0;
}

int ConjuntoPtr::cardinal() {
	return cant;
}

int ConjuntoPtr::ordinal(int e) {
	int c = 0;
	NodoConj* aux = ptrConj;
	while (aux != NULL) {
		c++; // empieza en 1
		if (aux->dato == e) {
			return c;
		}
		aux = aux->sig;
	}
	cout << "Error elemento no encontrado\n";
	return -1; // Devuelve -1 por que no lo encuentra
}

void ConjuntoPtr::inserta(int e) {
	if (!pertenece(e)) {
		NodoConj* dir = new NodoConj;
		if (dir != NULL) {
			dir->dato = e;
			dir->sig = ptrConj;
			ptrConj = dir;
			cant++;
		}
		else
			cout << "ERROR NO EXISTE ESPACIO EN LA MEMORIA\n";
	}
	else
		cout << "ERROR ELEMENTO YA EXISTE\n";
}

NodoConj* ConjuntoPtr::anterior(NodoConj *p) {
	if (this->vacio()) {
	}
	else if (p == ptrConj) {
	}
	else {
		NodoConj* x = ptrConj;
		NodoConj* ant = NULL;
		while (x != NULL) {
			if (x == p) {
				return ant;
			}
			ant = x;
			x = x->sig;
		}
	}
}

NodoConj* ConjuntoPtr::localiza(int e) {
	NodoConj* x = ptrConj;
	while (x != NULL) {
		if (x->dato == e)
			return x;
		x = x->sig;
	}
	return NULL;
}

void ConjuntoPtr::suprime(int e) {
	NodoConj* p = localiza(e);
	if (cant == 0) {
		return;
	}
	else if (p == ptrConj) {
		NodoConj* x = ptrConj;
		ptrConj = ptrConj->sig;
		delete(x);
	}
	else {
		NodoConj* ant = anterior(p);
		ant->sig = p->sig;
		delete(p);
	}
	cant--;
}

bool ConjuntoPtr::pertenece(int e) {
	NodoConj* x = ptrConj;
	while (x != NULL) {
		if (x->dato == e)
			return true;
		x = x->sig;
	}
	return false;
}

int ConjuntoPtr::muestrea() {
	if (!vacio()) {
		srand(time(NULL));
		int pos = rand() % cardinal();
		return elemento(pos);
	}
	else
		return 0;
}

int ConjuntoPtr::elemento(int pos) {
	int c = 0;
	NodoConj* aux = ptrConj;
	while (aux != NULL) {
		if (c == pos)
			return aux->dato;
		c++;
		aux = aux->sig;
	}
	return 0;
}

void ConjuntoPtr::reiniciar() {
	while (vacio() == false) {
		int r = muestrea();
		suprime(r);
	}
}

string ConjuntoPtr::toStr() {
	string r = "{";
	for (int i = 0; i < cant; i++) {
		r += to_string(elemento(i));
		if (i < cant - 1) {
			r += ",";
		}
	}
	r += "}";
	return r;
}

void ConjuntoPtr::unir(ConjuntoPtr * b, ConjuntoPtr * c) {
	c->reiniciar();
	ConjuntoPtr *aux = new ConjuntoPtr();
	ConjuntoPtr *a = this;
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

void ConjuntoPtr::intersectar(ConjuntoPtr * b, ConjuntoPtr * c) {
	c->reiniciar();
	ConjuntoPtr* a = this;
	ConjuntoPtr* aux = new ConjuntoPtr();
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

ConjuntoPtr* ConjuntoPtr::diferenciaSimetrica(ConjuntoPtr* b) {
	ConjuntoPtr* a = this;
	ConjuntoPtr* c = new ConjuntoPtr();
	for (int i = 0; i < a->cardinal(); i++) {
		int elemA = a->elemento(i);
		if (a->pertenece(elemA) && !b->pertenece(elemA)) {
			c->inserta(elemA);
		}
	}
	for (int i = 0; i < b->cardinal(); i++) {
		int elemB = b->elemento(i);
		if (b->pertenece(elemB) && !a->pertenece(elemB)) {
			c->inserta(elemB);
		}
	}
	return c;
}

// void ConjuntoPtr::complementoInterseccion(ConjuntoPtr a, ConjuntoPtr b,
// ConjuntoPtr &c) {
// for (int i = 0; i < a.cardinal(); i++) {
// int eA = a.elemento(i);
// if (!(a.pertenece(eA) && b.pertenece(eA))) {
// c.inserta(eA);
// }
// }
// for (int i = 0; i < b.cardinal(); i++) {
// int eB = b.elemento(i);
// if (!(a.pertenece(eB) && b.pertenece(eB))) {
// c.inserta(eB);
// }
// }
// }
