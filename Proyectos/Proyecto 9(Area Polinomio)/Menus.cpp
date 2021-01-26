// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Menus.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

void menuSm(CSMemoria* m, PoliSm *p) {
	cout << "Menu SMemoria\n";
	cout << "1.Crear Memoria\n";
	cout << "2.Pedir Espacio\n";
	cout << "3.Liberar Espacio\n";
	cout << "4.Crear Polinomio\n";
	cout << "5.Poner termino\n";
	cout << "6.Mostrar Polinomio\n";
	cout << "7.Derivar\n";
	cout << "8.Salir\n";
	int opcion;
	cout << "Elija su opcion : ";
	cin >> opcion;
	switch (opcion) {
	case 1: {
			m = new CSMemoria();
			cout << "Memoria creada\n";
		} break;
	case 2: {
			string id;
			cout << "Ingrese id's : ";
			cin.ignore();
			getline(cin, id);
			m->new_espacio(id);
		} break;
	case 3: {
			int dir;
			cout << "Direccion a liberar : ";
			cin >> dir;
			m->delete_espacio(dir);
		} break;
	case 4: {
			p = new PoliSm(m);
			cout << "Polinomio creado\n";
		} break;
	case 5: {
			int c, e;
			cout << "Coeficiente  : ";
			cin >> c;
			cout << "Exponente : ";
			cin >> e;
			p->poner_termino(c, e);
			cout << "Termino insertado\n";
		} break;
	case 6: {
			cout << p->toStr() << endl;
		} break;
	case 7: {
			p->derivar();
			cout << "Polinomio derivado\n";
		} break;
	case 8: {
			cout << "Finalizando correctamente\n";
		} break;
	}
	if (opcion != 8) {
		system("pause");
		system("cls");
		menuSm(m, p);
	}
}

void menuVector(PoliVector *p) {
	cout << "Menu Vectores\n";
	cout << "1.Crear Polinomio\n";
	cout << "2.Poner termino\n";
	cout << "3.Mostrar Polinomio\n";
	cout << "4.Derivar\n";
	cout << "5.Salir\n";
	int opcion;
	cout << "Elija su opcion : ";
	cin >> opcion;
	switch (opcion) {
	case 1: {
			p = new PoliVector();
			cout << "Polinomio creado\n";
		} break;
	case 2: {
			int c, e;
			cout << "Coeficiente  : ";
			cin >> c;
			cout << "Exponente : ";
			cin >> e;
			p->poner_termino(c, e);
			cout << "Termino insertado\n";
		} break;
	case 3: {
			cout << p->toStr() << endl;
		} break;
	case 4: {
			p->derivar();
			cout << "Polinomio derivado\n";
		} break;
	case 5: {
			cout << "Finalizando correctamente\n";
		} break;
	}
	if (opcion != 5) {
		system("pause");
		system("cls");
		menuVector(p);
	}
}

void menuPtr(PoliPtr *p) {
	cout << "Menu Punteros\n";
	cout << "1.Crear Polinomio\n";
	cout << "2.Poner termino\n";
	cout << "3.Mostrar Polinomio\n";
	cout << "4.Derivar\n";
	cout << "5.Salir\n";
	int opcion;
	cout << "Elija su opcion : ";
	cin >> opcion;
	switch (opcion) {
	case 1: {
			p = new PoliPtr();
			cout << "Polinomio creado\n";
		} break;
	case 2: {
			int c, e;
			cout << "Coeficiente  : ";
			cin >> c;
			cout << "Exponente : ";
			cin >> e;
			p->poner_termino(c, e);
			cout << "Termino insertado\n";
		} break;
	case 3: {
			cout << p->toStr() << endl;
		} break;
	case 4: {
			p->derivar();
			cout << "Polinomio derivado\n";
		} break;
	case 5: {
			cout << "Finalizando correctamente\n";
		} break;
	}
	if (opcion != 5) {
		system("pause");
		system("cls");
		menuPtr(p);
	}
}

void menuListaPtr(PoliListaPtr *p) {
	cout << "Menu ListaPtr\n";
	cout << "1.Crear Polinomio\n";
	cout << "2.Poner termino\n";
	cout << "3.Mostrar Polinomio\n";
	cout << "4.Derivar\n";
	cout << "5.Salir\n";
	int opcion;
	cout << "Elija su opcion : ";
	cin >> opcion;
	switch (opcion) {
	case 1: {
			p = new PoliListaPtr();
			cout << "Polinomio creado\n";
		} break;
	case 2: {
			int c, e;
			cout << "Coeficiente  : ";
			cin >> c;
			cout << "Exponente : ";
			cin >> e;
			p->poner_termino(c, e);
			cout << "Termino insertado\n";
		} break;
	case 3: {
			cout << p->toStr() << endl;
		} break;
	case 4: {
			p->derivar();
			cout << "Polinomio derivado\n";
		} break;
	case 5: {
			cout << "Finalizando correctamente\n";
		} break;
	}
	if (opcion != 5) {
		system("pause");
		system("cls");
		menuListaPtr(p);
	}
}

void menuListaSm(PoliListaSm *p) {
	cout << "Menu ListaSm\n";
	cout << "1.Crear Polinomio\n";
	cout << "2.Poner termino\n";
	cout << "3.Mostrar Polinomio\n";
	cout << "4.Derivar\n";
	cout << "5.Salir\n";
	int opcion;
	cout << "Elija su opcion : ";
	cin >> opcion;
	switch (opcion) {
	case 1: {
			p = new PoliListaSm();
			cout << "Polinomio creado\n";
		} break;
	case 2: {
			int c, e;
			cout << "Coeficiente  : ";
			cin >> c;
			cout << "Exponente : ";
			cin >> e;
			p->poner_termino(c, e);
			cout << "Termino insertado\n";
		} break;
	case 3: {
			cout << p->toStr() << endl;
		} break;
	case 4: {
			p->derivar();
			cout << "Polinomio derivado\n";
		} break;
	case 5: {
			cout << "Finalizando correctamente\n";
		} break;
	}
	if (opcion != 5) {
		system("pause");
		system("cls");
		menuListaSm(p);
	}
}
