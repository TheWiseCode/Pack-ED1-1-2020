#include <iostream>
#include <string>
#include "PilaSm.h"
#include "UMemoria.h"

using namespace std;

int main() {
	string cad = "(((((())))))";
	CSMemoria* mem = new CSMemoria();
	mem->new_espacio("dia,mes,año");
	PilaSm* pila = new PilaSm(mem);
	bool correcto = true;
	for (int i = 0; i < cad.length(); i++) {
		int s;
		char c = cad[i];
		if (c == '(')
			pila->meter(c);
		else if (c == ')') {
			if (pila->vacia()) {
				correcto = false;
				break;
			}
			pila->sacar(s);
		}
	}
	if (correcto && pila->vacia())
		cout << "Parentesis correctos\n";
	else
		cout << "Parentesis incorrectos\n";
	mem->mostrar_memoria();
	system("pause");
	return 0;
}
