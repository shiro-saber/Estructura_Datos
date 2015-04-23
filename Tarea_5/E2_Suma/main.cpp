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

	cout << endl << "E1 \n";
        nuevo->imprimir();
        cout << "\nLa sumatoria de los elementos es: " << endl;
	cout << nuevo->sumatoria() << endl << endl;
	
	//E2
	ArbolBinario<int> * lal = new ArbolBinario<int>();

	for (int i = 0; i<10; i++)
	{
		Nodo<int> *  lul = new Nodo<int>(rand() % 8);
		lal->Insert(lul);
	}

	cout << "E2 \n El arbol en pre-orden es: " << endl;

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

	cout << endl << "E3 \n El arbol en pre-orden es: " << endl;

	esto->preOrden();

	cout << endl;

	cout << endl << "El arbol reflejado en pre-orden es: " << endl;

	esto->arbolReflex();

	esto->preOrden();
	cout << endl;

	return 0;
}