#include <iostream>
#include <stdlib.h>
#include <fstream> //Libreria para leer y escribir textox
#include <stdio.h> //usos del codigo ascii
#include <string> //uso del getline
#include "PilaPtr.h"
#include "Funciones.h"

using namespace std;

string suma(string a, string b);
void suma2();
void suma2oMas();

int main() {
	suma2oMas();
	system("pause");
	return 0;
}

void suma2() {
	ifstream file;
	string r =
		"C:/Users/pc/Desktop/Aux ED1 1-2020/Proyectos ED1/Proyectos/Proyecto 2(Suma fuera de rango)/sumas.txt";
	char* ruta = (char*)r.c_str();
	file.open(ruta, ios::in);
	if (!file.fail()) {
		string a, b;
		getline(file, a);
		getline(file, b);
		cout << "Num a: " << a << endl;
		cout << "Num b: " << b << endl;
		string sum = suma(a, b);
		cout << "A+B = " << sum << endl;
	}
}

void suma2oMas() {
	ifstream file;
	string r =
		"C:/Users/pc/Desktop/Aux ED1 1-2020/Proyectos ED1/Proyectos/Proyecto 2(Suma fuera de rango)/sumas.txt";
	char* ruta = (char*)r.c_str();
	file.open(ruta, ios::in);
	if (!file.fail()) {
		string* nums = new string[100];
		int n = 0;
		while (!file.eof()) {
			string num;
			getline(file, num);
			cout << "Num[" << (n + 1) << "] = " << num << endl;
			nums[n] = num;
			n++;
		}
		string s = "0";
		for (int i = 0; i < n; i++) {
			s = suma(s, nums[i]);
		}
		cout << "Suma Total = " << s << endl;
		/* int nn = 5;
		 int* v = new int[nn];
		 v[0] = 1;
		 v[1] = 2;
		 v[2] = 3;
		 v[3] = 4;
		 v[4] = 5;
		 int sum = 0;
		 for (int i = 0; i < nn; i++) {
		 sum = sum + v[i];
		 }
		 cout << sum << endl; */

	}
}

string suma(string a, string b) {
	PilaPtr* p = new PilaPtr();
	int carry = 0;
	while (a.length() > 0 || b.length() > 0) {
		int digA = 0, digB = 0;
		if (a.length() > 0)
			digA = a[a.length() - 1] - 48;
		if (b.length() > 0)
			digB = b[b.length() - 1] - 48;
		int suma = carry + digA + digB;
		carry = suma / 10;
		int dig = suma % 10;
		if (a.length() > 0)
			a.erase(a.length() - 1, 1);
		if (b.length() > 0)
			b.erase(b.length() - 1, 1);
		p->meter(dig);
	}
	if (carry > 0)
		p->meter(carry);
	string ret = "";
	while (!p->vacia()) {
		int d;
		p->sacar(d);
		ret += to_string(d);
	}
	return ret;
}
