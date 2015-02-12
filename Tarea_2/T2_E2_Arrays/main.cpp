#include <iostream>
#include <cstdlib>
#include "OrdenamientoGenerico.h"
#include <algorithm>
#include <ostream>
#include <iterator>

#define N 6

using namespace std;

/*
Realice un programa que genere aleatoriamente 1000 cadenas de caracteres e imprima el
arreglo resultante de ordenarlas ascendente y descendentemente, utilizando el método de la
clase Ordenamiento seleccionado por el usuario
*/

typedef bool (*t_orden) (int, int);
typedef void (*t_algoritmo) (int[], int, t_orden); //defines el tipo de void, el * es el nombre y lo que recibe la funcion.

int genera()
{
    return rand() % 1000;
}

int main()
{
    const int n = 1000;
    int choice;
    int choice2;
    int enteros[n];

    //definicion del arreglo de funciones
    t_orden sharmutta[2]; //es el de ascendente o descendente
    sharmutta[0] = Ordenamiento<int>::asc;
    sharmutta[1] = Ordenamiento<int>::desc;

    t_algoritmo kuz[3];
    kuz[0] = Ordenamiento<int>::burbuja;
    kuz[1] = Ordenamiento<int>::seleccion;
    kuz[2] = Ordenamiento<int>::insercion;

    /* Establecer la semilla del generador de números aleatorios */
    srand((unsigned int) time(nullptr));

    /* Inicializar el arreglo con números aleatorios */
    generate(enteros, enteros+n, genera);

    /* Mostrar números por pantalla */
    cout << "Este es el arreglo generado sin ordenar" << endl << endl;
    copy(enteros, enteros+n, ostream_iterator<int>(cout, " "));
    cout << endl << endl;

    cout << "Elija una opción:\n1)burbuja\n2)insercion\n3)seleccion\n";
    cin >> choice;

    cout << "Elije la orientacion\n1)ascendente\n2)descendente\n";
    cin >> choice2;

    kuz[choice - 1](enteros, n, sharmutta[choice2 - 1]);

    cout << endl << "Este es el arreglo ordenado por el metodo elegido" << endl;
    cout << endl;
    copy(enteros, enteros+n, ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
