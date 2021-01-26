// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Juego.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	String ed = Edit1->Text;
	int num = StrToInt(ed);
	if (num >= 3 && num <= 7) {
		numDiscos = num;
		iniciarPilas();
		ponerEnMemo(torre1, Memo1);
		ponerEnMemo(torre2, Memo2);
		ponerEnMemo(torre3, Memo3);
	}
}

String TForm1::asteriscos(int n) {
	int max = numDiscos * 2 - 1;
	int le = n * 2 - 1;
	int mit = (max - le) / 2;
	String ret = "";
	for (int i = 0; i < mit; i++)
		ret += " ";
	for (int i = 0; i < le; i++)
		ret += "*";
	return ret;
}

void TForm1::ponerEnMemo(PilaPtr* pila, TMemo* memo) {
	memo->Text = "";
	PilaPtr* aux = new PilaPtr();
	while (!pila->vacia()) {
		int s;
		pila->sacar(s);
		aux->meter(s);
		String disco = asteriscos(s);
		memo->Lines->Add(disco);
	}
	while (!aux->vacia()) {
		int s;
		aux->sacar(s);
		pila->meter(s);
	}
}

void TForm1::iniciarPilas() {
	torre1 = new PilaPtr();
	torre2 = new PilaPtr();
	torre3 = new PilaPtr();
	for (int i = numDiscos; i >= 1; i--)
		torre1->meter(i);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
	int numTs = StrToInt(Edit2->Text);
	int numTm = StrToInt(Edit3->Text);
	if (numTs != numTm && numTs >= 1 && numTs <= 3 && numTm >= 1 && numTm <= 3)
	{
		mover(numTs, numTm);
	}
}

bool TForm1::gana() {
	return torre1->vacia() && torre2->vacia();
}

PilaPtr* TForm1::torre(int nro) {
	if (nro == 1)
		return torre1;
	else if (nro == 2)
		return torre2;
	else if (nro == 3)
		return torre3;
	return NULL;
}

void TForm1::mover(int numTs, int numTm) {
	PilaPtr* torreSaca = torre(numTs);
	PilaPtr* torreMuevo = torre(numTm);
	if (torreSaca->vacia())
		return;
	int nSac = torreSaca->cima();
	if (torreMuevo->vacia()) {
		int s;
		torreSaca->sacar(s);
		torreMuevo->meter(s);
	}
	else {
		int nMuev = torreMuevo->cima();
		if (nSac < nMuev) {
			int s;
			torreSaca->sacar(s);
			torreMuevo->meter(s);
		}
	}
	ponerEnMemo(torre1, Memo1);
	ponerEnMemo(torre2, Memo2);
	ponerEnMemo(torre3, Memo3);
	if (gana()) {
		ShowMessage("Gan�");
		iniciarPilas();
		ponerEnMemo(torre1, Memo1);
		ponerEnMemo(torre2, Memo2);
		ponerEnMemo(torre3, Memo3);
	}
}
// ---------------------------------------------------------------------------
