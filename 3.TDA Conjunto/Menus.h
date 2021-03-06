// ---------------------------------------------------------------------------

#ifndef MenusH
#define MenusH
// ---------------------------------------------------------------------------
#include <iostream>
#include "UConjuntoV.h"
#include "UConjuntoPtr.h"
#include "UConjuntoSm.h"
#include "UConjuntoListaPtr.h"
#include "UConjuntoLista.h"

using namespace std;

void p1();
void prueba();
void MenuSm(CSMemoria *m, ConjuntoSm* a, ConjuntoSm* b, ConjuntoSm* c);
void MenuVector(ConjuntoV *a, ConjuntoV *b, ConjuntoV *c);
void MenuLista(ConjuntoLista *a, ConjuntoLista *b, ConjuntoLista *c);
void MenuListaPtr(ConjuntoListaPtr *a, ConjuntoListaPtr *b,
	ConjuntoListaPtr *c);
void MenuPtr(ConjuntoPtr *a, ConjuntoPtr *b, ConjuntoPtr *c);

#endif
