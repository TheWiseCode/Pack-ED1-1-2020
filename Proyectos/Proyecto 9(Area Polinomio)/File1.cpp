#include <iostream>
#include "UPoliVector.h"
#include "UPoliPtr.h"
#include "UPoliSm.h"
#include "UPoliListaPtr.h"
#include "UPoliListaSm.h"
#include "UMemoria.h"
#include "Menus.h"

using namespace std;

void menu();

int main() {
	menu();
	system("pause");
	return 0;
}

void menu() {
	PoliPtr* p;
	int opcion;
	do {
		cout << "1) Crear" << endl;
		cout << "2) Poner Termino" << endl;
		cout << "3) Grado polinomio" << endl;
		cout << "4) Derivada" << endl;
		cout << "5) Area en intervalo a,b" << endl;
		cout << "6) Mostrar Polinomio" << endl;
		cout << "7) Salir" << endl;
		cout << "Opcion: " << endl;
		cin >> opcion;
		switch (opcion) {
		case 1:
			p = new PoliPtr();
			break;
		case 2: {
				int e, c;
				cout << "Coeficiente: ";
				cin >> c;
				cout << "Exponente: ";
				cin >> e;
				p->poner_termino(c, e);
			} break;
		case 3: {
				int grado = p->grado();
				cout << "Grado polinomio: " << grado << endl;
			} break;
		case 4: {
				p->derivar();
			} break;
		case 5: {
				float a, b;
				cout << "a: ";
				cin >> a;
				cout << "b: ";
				cin >> b;
				float ar = p->area(a, b);
				cout << "Area: " << ar << endl;
			} break;
		case 6:
			cout << p->toStr() << endl;
			break;
		case 7:
			cout << "Saliendo..." << endl;
			break;
		};
		system("pause");
		system("cls");
	}
	while (opcion != 7);
}
