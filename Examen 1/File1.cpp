#include <iostream>
#include "UMemoria.h"
#include "ListaSm.h"
#include "UConjuntoSm.h"
#include "UPoliSm.h"
#include "UPoliListaPtr.h"

using namespace std;

int main() {
	CSMemoria* m = new CSMemoria;
	ListaSm* l = new ListaSm(m);
	ConjuntoSm* c = new ConjuntoSm(m);
	PoliSm*p = new PoliSm(m);
	m->new_espacio(" ");
	m->new_espacio(" ");
	m->new_espacio(" ");
	m->new_espacio(" ");
	m->new_espacio(" ");
	m->new_espacio(" ");
	m->new_espacio(" ");
	m->delete_espacio(5);
	m->delete_espacio(4);
	m->delete_espacio(2);
	// Examen
	/*
	 m->delete_espacio(0); // 211223344
	 l->inserta(l->primero(), 61); // Aqui pongan x
	 l->inserta(l->primero(), 20); // Aqui pongan y
	 m->delete_espacio(1);
	 c->inserta(01); // Aqui pongan z
	 p->poner_termino(2, 5);
	 m->delete_espacio(6);
	 l->inserta(l->fin(), 17); // Aqui pongan w
	 */
	m->mostrar_memoria();
	/*
	/* PoliListaPtr* p = new PoliListaPtr();
	 p->poner2(4, 7);
	 p->poner2(-4, 7);
	 p->mostrar(); */
	system("pause");
	return 0;
}
