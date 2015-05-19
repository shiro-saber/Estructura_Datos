#include <iostream>
#include "ArbolBinario.h"

using namespace std;

int main(int argc, const char * argv[]) 
{
    //este es con preorden
        char pre[] = { 'G', 'E', 'A', 'I', 'B', 'M', 'C', 'L', 'D', 'F', 'K', 'J', 'H' };
	char in[] = { 'I', 'A', 'B', 'E', 'G', 'L', 'D', 'C', 'F', 'M', 'K', 'H', 'J' };
        char pos[] = { 'G', 'E', 'M', 'A', 'C', 'K', 'I', 'B', 'L', 'F', 'J', 'D', 'H' }; //armado con la logica de arboles
	
        int length = sizeof(in) / sizeof(in[0]);

	cout << endl << "arbol creado con preorden" << endl;

	ArbolBinario<char> * nu = new ArbolBinario<char>();
	Nodo<char> * n = new Nodo<char>(*nu->creaArbol(pre, 0, (length-1), in, 0, (length-1)));
	nu = new ArbolBinario<char>(n);
	nu->preOrden();
	cout << endl << endl;

	nu->imprimir();

	//Este es con inorden
	cout << endl << "arbol con inorden" << endl;

	ArbolBinario<char> *na = new ArbolBinario<char>();
	Nodo<char> * v = new Nodo<char>(*na->creaArbolPosO(pos, 0, length - 1, in, 0, length - 1));
	na = new ArbolBinario<char>(v);
	na->inOrden();
	cout << endl << endl;
	na->imprimir();
	cout << endl;

    return 0;
}

