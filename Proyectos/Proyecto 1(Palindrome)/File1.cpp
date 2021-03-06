#include <iostream>
#include <fstream>
#include <string>
#include "ColaPtr.h"
#include "PilaPtr.h"

using namespace std;

bool es_palindrome(string s);
int cantidad_palindromes(string linea);

int main() {
	ifstream file;
	string r =
		"C:/Users/pc/Desktop/Aux ED1 1-2020/Proyectos ED1/Proyectos/Proyecto 1(Palindrome)/Palindrome.txt";
	char* ruta = (char*) r.c_str();
	file.open(ruta, ios::in);
	if (!file.fail()) { // Se abrio correctamente el archivo
		string* lineas = new string[100];
		int n = 0;
		while (!file.eof()) {
			string linea;
			getline(file, linea);
			lineas[n] = linea;
			n++;
		}
		int c = 0;
		for (int i = 0; i < n; i++) {
			c = c + cantidad_palindromes(lineas[i]);
		}
		cout << "Cantidad de palabras palindromes: " << c << endl;
	}
	system("pause");
	return 0;
}

int cantidad_palindromes(string linea) {
	int c = 0;
	while (linea.length() > 0) {
		int pos = linea.find_first_of(" ");
		if (pos == -1)
			pos = linea.length();
		string pal = linea.substr(0, pos);
		if (es_palindrome(pal))
			c++;
		linea.erase(0, pos + 1);
	}
	return c;
}

bool es_palindrome(string s) {
	ColaPtr* cola = new ColaPtr();
	PilaPtr* pila = new PilaPtr();
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		cola->poner(c);
		pila->meter(c);
	}
	while (!cola->vacia() && !pila->vacia()) {
		int sc, sp;
		cola->sacar(sc);
		pila->sacar(sp);
		if (sc != sp)
			return false;
	}
	return true;
}
