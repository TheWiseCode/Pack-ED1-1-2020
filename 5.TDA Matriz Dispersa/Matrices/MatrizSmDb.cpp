// ---------------------------------------------------------------------------

#pragma hdrstop

#include "MatrizSmDb.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

MatrizSmDb::MatrizSmDb() {
	mem = new CSMemoria();
	ptrMat = nulo;
	df = 0;
	dc = 0;
	rep = 0;
}

MatrizSmDb::MatrizSmDb(CSMemoria* m) {
	mem = m;
	ptrMat = nulo;
	df = 0;
	dc = 0;
	rep = 0;
}

void MatrizSmDb::dimensionar(int f, int c) {
	df = f;
	dc = c;
}

int MatrizSmDb::dimension_fila() {
	return df;
}

int MatrizSmDb::dimension_columna() {
	return dc;
}

int MatrizSmDb::existe_fil(int f) {
	int aux = ptrMat;
	while (aux != nulo) {
		int aux_fil = mem->obtener_dato(aux, filSm);
		if (aux_fil == f)
			return aux;
		aux = mem->obtener_dato(aux, sigF); // aux->sigF;
	}
	return nulo;
}

int MatrizSmDb::existe_col(int f, int c) {
	if (f == nulo)
		return nulo;
	int f_ptrCol = mem->obtener_dato(f, ptrCol);
	int aux = f_ptrCol;
	while (aux != nulo) {
		int aux_col = mem->obtener_dato(aux, colSm);
		if (aux_col == c)
			return aux;
		aux = mem->obtener_dato(aux, sigC); // aux->sigC;
	}
	return nulo;
}

void MatrizSmDb::insertar_fila(int nf) {
	if (ptrMat == nulo) {
		ptrMat = nf;
	}
	else {
		int aux = ptrMat;
		int antSiFinaliza;
		while (aux != nulo) {
			antSiFinaliza = aux;
			int nf_fil = mem->obtener_dato(nf, filSm);
			int aux_fil = mem->obtener_dato(aux, filSm);
			if (nf_fil < aux_fil) {
				if (aux == ptrMat) {
					ptrMat == nf;
					mem->poner_dato(nf, antF, nulo); // nf->antF = nulo;
					mem->poner_dato(nf, sigF, aux); // nf->sigF = aux;
					mem->poner_dato(aux, antF, nf); // aux->antF = nf;
				}
				else {
					int aux_antF = mem->obtener_dato(aux, antF);
					int ant = aux_antF;
					mem->poner_dato(ant, sigF, nf); // ant->sigF = nf;
					mem->poner_dato(aux, antF, nf); // aux->antF = nf;
					mem->poner_dato(nf, antF, ant); // nf->antF = ant;
					mem->poner_dato(nf, sigF, aux); // nf->sigF = aux;
				}
				return;
			}
			aux = mem->obtener_dato(aux, sigF); // aux->sigF;
		}
		// Inserta al final
		mem->poner_dato(antSiFinaliza, sigF, nf); // antSiFinaliza->sigF = nf;
		mem->poner_dato(nf, antF, antSiFinaliza); // nf->antF = antSiFinaliza;
		mem->poner_dato(nf, sigF, nulo); // nf->sigF = nulo;

	}
}

void MatrizSmDb::insertar_col(int nf, int nc) {
	int nf_ptrCol = mem->obtener_dato(nf, ptrCol);
	if (nf_ptrCol == nulo) {
		mem->poner_dato(nf, ptrCol, nc); // nf->ptrCol = nc;
	}
	else {
		mem->poner_dato(nc, sigC, nf_ptrCol); // nc->sigC = nf->ptrCol;
		mem->poner_dato(nf, ptrCol, nc); // nf->ptrCol = nc;
	}
}

int MatrizSmDb::anterior(int nf, int p) {
	int nf_ptrCol = mem->obtener_dato(nf, ptrCol);
	if (p == nf_ptrCol) {
		return nulo;
	}
	else {
		int x = nf_ptrCol;
		int ant = nulo;
		while (x != nulo) {
			if (x == p) {
				return ant;
			}
			ant = x;
			x = mem->obtener_dato(x, sigC); // x->sigC;
		}
	}
}

void MatrizSmDb::suprime(int nf, int p) {
	int nf_ptrCol = mem->obtener_dato(nf, ptrCol);
	if (p == nf_ptrCol) {
		int x = nf_ptrCol;
		int nf_ptrCol_sigC = mem->obtener_dato(nf_ptrCol, sigC);
		mem->poner_dato(nf, ptrCol, nf_ptrCol_sigC);
		// nf->ptrCol = nf->ptrCol->sigC;
		mem->delete_espacio(x); // delete(x);
	}
	else {
		int ant = anterior(nf, p);
		int p_sigC = mem->obtener_dato(p, sigC);
		mem->poner_dato(ant, sigC, p_sigC); // ant->sigC = p->sigC;
		mem->delete_espacio(p); // delete(p);
	}
	int nt_ptrCol = mem->obtener_dato(nf, ptrCol);
	if (nt_ptrCol == nulo) {
		if (nf == ptrMat) {
			ptrMat = mem->obtener_dato(ptrMat, sigF); // ptrMat->sigF;
			mem->poner_dato(ptrMat, antF, nulo); // ptrMat->antF = NULL;
			mem->delete_espacio(nf); // delete(nf);
		}
		else {
			int ant = mem->obtener_dato(nf, antF); // nf->antF;
			int sig = mem->obtener_dato(nf, sigF); // nf->sigF;
			mem->poner_dato(ant, sigF, sig); // ant->sigF = sig;
			if (sig != nulo)
				mem->poner_dato(sig, antF, ant); // sig->antF = ant;
			mem->delete_espacio(nf); // delete(nf);
		}
	}
}

void MatrizSmDb::poner(int f, int c, int valor) {
	if (f > 0 && f <= df) {
		if (c > 0 && c <= dc) {
			int fila = existe_fil(f);
			if (fila != nulo) {
				int col = existe_col(fila, c);
				if (col == nulo) {
					int nuevaCol = mem->new_espacio(dataCol);
					mem->poner_dato(nuevaCol, colSm, c); // nuevaCol->col = c;
					mem->poner_dato(nuevaCol, datoSm, valor);
					// nuevaCol->dato = valor;
					mem->poner_dato(nuevaCol, sigC, nulo);
					// nuevaCol->sigC = nulo;
					insertar_col(fila, nuevaCol);
					nt++;
				}
				else {
					mem->poner_dato(col, datoSm, valor); // col->dato = valor;
				}
			}
			else {
				if (valor != rep) {
					int nuevoFil = mem->new_espacio(dataFil);
					mem->poner_dato(nuevoFil, filSm, f); // nuevoFil->fil = f;
					mem->poner_dato(nuevoFil, sigF, nulo);
					mem->poner_dato(nuevoFil, sigF, nulo);
					mem->poner_dato(nuevoFil, ptrCol, nulo);
					// nuevoFil->ptrCol = nulo;
					insertar_fila(nuevoFil);
					int nuevaCol = mem->new_espacio(dataCol);
					mem->poner_dato(nuevaCol, colSm, c); // nuevaCol->col = c;
					mem->poner_dato(nuevaCol, datoSm, valor);
					// nuevaCol->dato = valor;
					mem->poner_dato(nuevaCol, sigC, nulo);
					// nuevaCol->sigC = nulo;
					insertar_col(nuevoFil, nuevaCol);
					nt++;
				}
			}
			return;
		}
	}
	cout << "ERROR DE RANGO\n";
}

int MatrizSmDb::elemento(int f, int c) {
	if (f > 0 && f <= df) {
		if (c > 0 && c <= dc) {
			int fila = existe_fil(f);
			int col = existe_col(fila, c);
			if (fila != nulo && col != nulo) {
				return mem->obtener_dato(col, datoSm); // col->dato;
			}
			else {
				return rep;
			}
		}
	}
	cout << "ERROR DE RANGO\n";
}

void MatrizSmDb::definir_valor_repetido(int r) {
	rep = r;
}

string MatrizSmDb::toStr() {
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
