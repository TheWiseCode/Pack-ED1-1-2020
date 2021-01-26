// ---------------------------------------------------------------------------

#ifndef FuncionesH
#define FuncionesH

// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

string to_string(int value) {
	if (value == 0)
		return "0";
	bool es_negativo = value < 0;
	string r = "";
	if (es_negativo)
		value *= -1;
	while (value != 0) {
		char c = value % 10 + 0x30;
		r = c + r;
		value = value / 10;
	}
	return es_negativo ? "-" + r : r;
}
#endif
