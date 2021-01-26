// ---------------------------------------------------------------------------

#pragma hdrstop

#include "MatrizSm.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

// ---------------------------------------------------------------------------
MatrizSm::MatrizSm() {
	mem = new CSMemoria();
	ptrMat = nulo;
	df = 0;
	dc = 0;
	rep = 0;
}

MatrizSm::MatrizSm(CSMemoria* m) {
	mem = m;
	ptrMat = nulo;
	df = 0;
	dc = 0;
	rep = 0;
}

void MatrizSm::dimensionar(int f, int c) {
	df = f;
	dc = c;
}

int MatrizSm::dimension_fila() {
	return df;
}

int MatrizSm::dimension_columna() {
	return dc;
}

int MatrizSm::existe(int f, int c) {
	// if (f > 0 && f <= df) {
	// if (c > 0 && c <= dc) {
	int aux = ptrMat;
	while (aux != nulo) {
		int aux_fil = mem->obtener_dato(aux, filM); // "->fil";aux->fil
		int aux_col = mem->obtener_dato(aux, colM); // "->col";aux->col
		if (aux_fil == f && aux_col == c)
			return aux;
		int aux_sig = mem->obtener_dato(aux, sigM); // "->sig";aux->sig
		aux = aux_sig;
	}
	return nulo;
	// }
	// }
}

int MatrizSm::anterior(int p) {
	if (nt == 0 || p == ptrMat) {
		return nulo;
	}
	else {
		int x = ptrMat;
		int ant = nulo;
		while (x != nulo) {
			if (x == p) {
				return ant;
			}
			ant = x;
			int x_sig = mem->obtener_dato(x, sigM); // "->sig";x->sig
			x = x_sig;
		}
	}
}

void MatrizSm::suprime(int p) {
	if (nt == 0) {
		return;
	}
	else if (p == ptrMat) {
		int x = ptrMat;
		int ptrMat_sig = mem->obtener_dato(ptrMat, sigM); // ptrMat->sig;
		ptrMat = ptrMat_sig;
		mem->delete_espacio(x); // delete(x);
	}
	else {
		int ant = anterior(p);
		int p_sig = mem->obtener_dato(p, sigM); // "->sig",p->sig;
		mem->poner_dato(ant, sigM, p_sig); // ant->sig = p->sig;
		mem->delete_espacio(p); // delete(p);
	}
}

void MatrizSm::poner(int f, int c, int valor) {
	if (f > 0 && f <= df) {
		if (c > 0 && c <= dc) {
			int pos = existe(f, c);
			if (pos == nulo && valor != rep) {
				int nuevo = mem->new_espacio(dataM);
				mem->poner_dato(nuevo, filM, f); // nuevo->fil = f;
				mem->poner_dato(nuevo, colM, c); // nuevo->col = c;
				mem->poner_dato(nuevo, datoM, valor); // nuevo->dato = valor;
				mem->poner_dato(nuevo, sigM, ptrMat); // nuevo->sig = ptrMat;
				ptrMat = nuevo;
				nt++;
			}
			else {
				mem->poner_dato(pos, datoM, valor); // pos->dato = valor;
				if (valor == rep) {
					suprime(pos);
					nt--;
				}
			}
			return;
		}
	}
	cout << "ERROR DE RANGO\n";
}

int MatrizSm::elemento(int f, int c) {
	if (f > 0 && f <= df) {
		if (c > 0 && c <= dc) {
			int pos = existe(f, c);
			if (pos == nulo)
				return rep;
			else{
				int pos_dato = mem->obtener_dato(pos,datoM);
				return pos_dato;
			}
		}
	}
	cout << "ERROR DE RANGO\n";
}

void MatrizSm::definir_valor_repetido(int r) {
	rep = r;
}

string MatrizSm::toStr() {
	string r = "";
	for (int i = 0; i < df; i++) {
		r += "|";
		for (int j = 0; j < dc; j++) {
			r += to_string(elemento(i + 1, j + 1));
			if (j < dc - 1)
				r += "	";
		}
		r += "|\n";
	}
	return r;
}
