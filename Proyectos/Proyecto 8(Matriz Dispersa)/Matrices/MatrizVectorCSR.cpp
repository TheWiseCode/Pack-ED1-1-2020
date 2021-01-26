// ---------------------------------------------------------------------------

#pragma hdrstop

#include "MatrizVectorCSR.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

// ---------------------------------------------------------------------------

#pragma hdrstop

#include "MatrizVectorCSR.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

MatrizVectorCSR::MatrizVectorCSR() {
	df = 0;
	dc = 0;
	rep = 0;
	nt = 0;
	vf = new int[df + 1];
	vc = new int[df * dc];
	vd = new int[df * dc];
	for (int i = 0; i < df + 1; i++)
		vf[i] = 1;
}

void MatrizVectorCSR::dimensionar(int f, int c) {
	df = f;
	dc = c;
	vf = new int[df + 1];
	vc = new int[df * dc];
	vd = new int[df * dc];
	for (int i = 0; i < df + 1; i++)
		vf[i] = 1;
}

int MatrizVectorCSR::dimension_fila() {
	return df;
}

int MatrizVectorCSR::dimension_columna() {
	return dc;
}

int MatrizVectorCSR::numero_casillas_validas() {
	int c = 0;
	int n = df * dc;
	for (int i = 0; i < n; i++) {
		if (vf[i] == 0)
			break;
		c++;
	}
	return c;
}

int MatrizVectorCSR::posicion_insertar(int f) {
	int suma = 0;
	for (int i = 0; i < f; i++) {
		suma = suma + (vf[i + 1] - vf[i]);
	}
	return suma;
}

void MatrizVectorCSR::poner(int f, int c, int valor) {
	if (f > 0 && f <= df) {
		if (c > 0 && c <= dc) {
			int existe = posicion(f, c);
			if (existe == -1) {
				int pos = posicion_insertar(f);
				insertar_en_vector(vc, nt, pos, c);
				insertar_en_vector(vd, nt, pos, valor);
				nt++;
				for (int i = f; i < df + 1; i++)
					vf[i]++;
				// cout << toString(vd, nt) << endl;
				// cout << toString(vc, nt) << endl;
				// cout << toString(vf, df + 1) << endl;
			}
			else {
				vd[existe] = valor;
			}
			return;
		}
	}
	cout << "ERROR DE RANGO\n";
}

int MatrizVectorCSR::posicion(int f, int c) {
	int pos_inicial = 0;
	for (int i = 0; i < f - 1; i++) {
		pos_inicial += (vf[i + 1] - vf[i]);
	}
	int max = vf[f] - vf[f - 1];
	for (int i = 0; i < max; i++) {
		if (vc[pos_inicial + i] == c)
			return pos_inicial + i;
	}
	return -1;
}

int MatrizVectorCSR::elemento(int f, int c) {
	if (f > 0 && f <= df) {
		if (c > 0 && c <= dc) {
			int pos = posicion(f, c);
			if (pos == -1)
				return rep;
			else
				return vd[pos];
		}
	}
	cout << "ERROR DE RANGO\n";
}

void MatrizVectorCSR::definir_valor_repetido(int r) {
	rep = r;
}

string MatrizVectorCSR::toStr() {
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
