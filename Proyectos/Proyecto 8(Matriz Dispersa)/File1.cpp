#include <iostream>
#include "MatrizVector.h"
#include "MatrizVectorCSR.h"
#include "MatrizPtr.h"
#include "MatrizPtrDb.h"
#include "MatrizSm.h"
#include "MatrizSmDb.h"
#include "UMemoria.h"

using namespace std;

void menu();

int main() {
	menu();
	system("pause");
	return 0;
}

/*
 1) Crear Matriz
 2) Definir Valor por Defecto
 3) Dimensionar
 4) Poner
 5) Elemento
 6) Encontrar el promedio elementos
 7) Mostrar Matriz
 8) Mostrar Atributos
 9) Salir
 */
void menu() {
	MatrizPtr* mat;
	int opcion;
	do {
		cout << "1) Crear Matriz" << endl;
		cout << "2) Definir valor por defecto" << endl;
		cout << "3) Dimensionar" << endl;
		cout << "4) Poner" << endl;
		cout << "5) Elemento" << endl;
		cout << "6) Encontrar promedio elementos" << endl;
		cout << "7) Mostrar Matriz" << endl;
		cout << "8) Mostrar Atributos" << endl;
		cout << "9) Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			mat = new MatrizPtr();
			break;
		case 2: {
				int v;
				cout << "Valor por defecto: ";
				cin >> v;
				mat->definir_valor_repetido(v);
			} break;
		case 3: {
				int f, c;
				cout << "Filas: ";
				cin >> f;
				cout << "Columnas: ";
				cin >> c;
				mat->dimensionar(f, c);
			} break;
		case 4: {
				int f, c, d;
				cout << "Fila: ";
				cin >> f;
				cout << "Columna: ";
				cin >> c;
				cout << "Dato: ";
				cin >> d;
				mat->poner(f, c, d);
			} break;
		case 5: {
				int f, c;
				cout << "Fila: ";
				cin >> f;
				cout << "Columna: ";
				cin >> c;
				int d = mat->elemento(f, c);
				cout << "Elemento: " << d << endl;
			} break;
		case 6: {
				float prom = mat->prom_elementos_validos();
				cout << "Promedio: " << prom << endl;
			} break;
		case 7: {
				string s = mat->toStr();
				cout << s;
			} break;
		case 8:
			mat->mostrar_atr();
			break;
		case 9:
			cout << "Saliendo..." << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	while (opcion != 9);
}
