#include <iostream>
#include "UPoliVector.h"
#include "UPoliPtr.h"
#include "UPoliSm.h"
#include "UPoliListaPtr.h"
#include "UPoliListaSm.h"
#include "UMemoria.h"
#include "Funciones.h"
#include "Menus.h"

#include <math.h>
using namespace std;

double valorEvaluado(PoliPtr &p, double x) {
	int n = p.numero_terminos();
	double *coeficientes = new double[n];
	int *exponentes = new int[n];
	int c = 0;
	while (c < n) {
		int exp = p.exponente(c);
		int coef = p.coeficiente(exp);
		coeficientes[c] = coef * 1.0 / (exp + 1);
		exponentes[c] = exp + 1;
		c++;
	}
	double suma = 0;
	int i = 0;
	while (i < n) {
		suma += coeficientes[i] * pow(x, exponentes[i]);
		i++;
	}
	return suma;
}

void mostrar_area(PoliPtr &p, int a, int b) {
	double valor_a = valorEvaluado(p, a);
	double valor_b = valorEvaluado(p, b);
	double area = abs(valor_b - valor_a);
	cout << "Area del polinomio: " << area << endl;
}

double evaluaIntegral(PoliPtr* p, double x) {
	int n = p->numero_terminos();
	double *coef = new double[n];
	int *exp = new int[n];
	for (int i = 0; i < n; i++) {
		int e = p->exponente(i);
		int c = p->coeficiente(e);
		coef[i] = c * 1.0 / (e + 1);
		exp[i] = e + 1;
	}
	double evalua = 0;
	for (int i = 0; i < n; i++) {
		evalua = evalua + coef[i] * pow(x, exp[i]);
	}
	return evalua;
}

void area(PoliPtr* p, int a, int b) {
	double ea = evaluaIntegral(p, a);
	double eb = evaluaIntegral(p, b);
	double area = abs(eb - ea);
	cout << "Area : " << area << endl;
}

void area1(PoliPtr* p, int a, int b) {
	PoliPtr* integral = p->integral();
	double ar = abs(integral->evaluar(b) - integral->evaluar(a));
	cout << "Area del polinomio entre a y b : " << ar << endl;
}

void punto_minimo(PoliPtr* p, int a, int b) {
	double x_min = a;
	double x = a;
	double y = p->evaluar(x);
	while (x <= b) {
		x = x + 0.1;
		if (p->evaluar(x) < y) {
			x_min = x;
			y = p->evaluar(x);
		}
	}
	cout << "Punto Minimo : (" << x_min << "," << y << ")\n";
}

void integrar(PoliPtr &p) {
	for (int i = 0; i < p.numero_terminos(); i++) {
		int exp = p.exponente(i);
		double coef = p.coeficiente(exp);
		p.poner_termino(-coef, exp);
		p.poner_termino(coef*1.0 / (exp + 1), exp + 1);
	}
}

void MostrarIntegral(PoliPtr p) {
	int n = p.numero_terminos();
	float *coefs = new float[n];
	int *exps = new int[n];
	for (int i = 0; i < n; i++) {
		int exp = p.exponente(i);
		coefs[i] = p.coeficiente(exp);
		exps[i] = exp + 1;
	}
	string integral = "";
	for (int i = 0; i < n; i++) {
		int coef = coefs[i];
		int nExp = exps[i];
		integral += "(" + to_string(coef) + "x" + to_string(nExp) + ")/" +
			to_string(nExp) + "  +";
	}
	integral += " C";
	cout << integral << endl;
}

void mostrarIntegral(PoliPtr fx) {
	int num = fx.numero_terminos();
	for (int i = 0; i < num; i++) {
		int exp = fx.exponente(i);
		int coef = fx.coeficiente(exp);
		cout << "(" << coef << "X^" << (exp + 1) << ")/" << (exp + 1) << " + ";
	}
	cout << "C" << endl;
}

int main() {
	PoliPtr p;
	p.poner_termino(15, 2);
	p.poner_termino(3, 0);
	cout << p.toStr() << endl;
	MostrarIntegral(p);
	mostrarIntegral(p);
	/*
	 PoliPtr* pp = new PoliPtr();
	 pp->poner_termino(5, 3);
	 pp->poner_termino(-4, 2);
	 cout << pp->toStr() << endl;
	 area1(pp, -1, 2);
	 system("pause");
	 PoliPtr p;
	 p.poner_termino(3, 3);
	 p.poner_termino(5, 2);
	 p.poner_termino(-10, 0);
	 cout << p.toStr() << endl;
	 double fx = p.area(1, 2);
	 cout << "Area : " << to_string(fx) << endl;
	 system("pause");
	 cout << "1.Poli Memoria simulada\n";
	 cout << "2.Poli Vector\n";
	 cout << "3.Poli Ptr\n";
	 cout << "4.Poli ListaPtr\n";
	 cout << "5.Poli ListaSm\n";
	 int opcion;
	 cout << "Elija su opcion : ";
	 cin >> opcion;
	 system("cls");
	 if (opcion == 1) {
	 CSMemoria *m;
	 PoliSm *p;
	 menuSm(m, p);
	 }
	 else if (opcion == 2) {
	 PoliVector *p;
	 menuVector(p);
	 }
	 else if (opcion == 3) {
	 PoliPtr *p;
	 menuPtr(p);
	 }
	 else if (opcion == 4) {
	 PoliListaPtr *p;
	 menuListaPtr(p);
	 }
	 else if (opcion == 5) {
	 PoliListaSm *p;
	 menuListaSm(p);
	 } */
	system("pause");
	return 0;
}
