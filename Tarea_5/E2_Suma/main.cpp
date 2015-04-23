#include <iostream>
#include "ArbolBinario.h"

using namespace std;

int main(int argc, const char * argv[])
{
	//E1
	ArbolBinario<int> * nuevo = new ArbolBinario<int>();

	for (int i = 0; i<10; i++)
	{
		Nodo<int> *  ele = new Nodo<int>(rand() % 8);
		nuevo->Insert(ele);
	}

	cout << endl << "La sumatoria de los elementos es: " << endl;
	cout << nuevo->sumatoria() << endl << endl;
	
	//E4
	ArbolBinario<int> * lal = new ArbolBinario<int>();

	for (int i = 0; i<10; i++)
	{
		Nodo<int> *  lul = new Nodo<int>(rand() % 8);
		lal->Insert(lul);
	}

	cout << "El arbol en pre-orden es: " << endl;

	lal->preOrden();

	cout << endl;

	cout << endl << "El nuevo arbol con elementos sumados son: " << endl;

	ArbolBinario<int> * no = nuevo->copiar();

	no->sumaArbol();

	no->preOrden();
	cout << endl;

	//E3
	ArbolBinario<int> * esto = new ArbolBinario<int>();

	for (int i = 0; i<10; i++)
	{
		Nodo<int> *  lol = new Nodo<int>(rand() % 8);
		esto->Insert(lol);
	}

	cout << endl << "El arbol en pre-orden es: " << endl;

	esto->preOrden();

	cout << endl;

	cout << endl << "El arbol reflejado en pre-orden es: " << endl;

	esto->arbolReflex();

	esto->preOrden();
	cout << endl;

	//E4
	char pre[] = { '$', '%', 'A', '&', '#' };
	char in[] = { 'A', '%', '&', '$', '#' };
	char pos[] = { 'A', '&', '%', '#', '$' };

	int length = sizeof(in) / sizeof(in[0]);


	cout << endl << "arbol creado con inorden y preorden" << endl;

	ArbolBinario<char> * nu = new ArbolBinario<char>();
	Nodo<char> * n = new Nodo<char>(*nu->creaArbol(pre, 0, length - 1, in, 0, length - 1));
	nu = new ArbolBinario<char>(n);
	nu->preOrden();
	cout << endl << endl;

	nu->imprimir();

	//E5
	cout << endl << "arbol ccon pozole e inorden" << endl;

	ArbolBinario<char> *na = new ArbolBinario<char>();
	Nodo<char> * v = new Nodo<char>(*na->creaArbolPosO(pos, 0, length - 1, in, 0, length - 1));
	na = new ArbolBinario<char>(v);
	na->inOrden();
	cout << endl << endl;
	na->imprimir();
	cout << endl;

	system("PAUSE");
	return 0;
}