#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include "Libro.h"
#include "OrdenamientoGenerico.h"

using namespace std;

/*
Si se tiene un arreglo de libros y de cada libro se conoce su título, editorial, año de publicación,
número de páginas y edición, realice un programa que permita ordenar los libros por el criterio
(título, año o edición), algoritmo de ordenamiento y dirección (ascendente o descendente)
seleccionados por el usuario.
*/

typedef bool (*t_orden) (Libro, Libro); //definimos un tipo que es bool como nuestras funciones
typedef void (*t_algoritmo) (Libro[], int, t_orden); //defines el tipo de void como nuestras funciones, el * es el nombre y lo que recibe la funcion.

int main()
{
    int choice;
    int choice2;

    /*declaracion del arreglo de libros */
    const int n_libros = 5;
    Libro libros[n_libros]; //definimos el arreglo de libros

    libros[0] = Libro("Gabriel Garcia Marquez", "Cien Años de Soledad", 150, 2, "Porrua", 2001);
    libros[1] = Libro("Ruben Dario", "Azul", 265, 3, "Barco de Vapor", 2006);
    libros[2] = Libro("Stephen King", "IT", 1115, 1, "De Bolsillo", 2010);
    libros[3] = Libro("Stephen Hawking", "Theory of Everything", 3520, 8, "Mc Graw Hill", 2000);
    libros[4] = Libro("J. R. Tolkien", "The Hobbit", 356, 1, "No se", 1984);

    //definicion del arreglo de funciones
    t_orden sharmutta[2]; //es el de ascendente o descendente
    sharmutta[0] = Ordenamiento<Libro>::asc;
    sharmutta[1] = Ordenamiento<Libro>::desc;

    t_algoritmo kuz[3];
    kuz[0] = Ordenamiento<Libro>::burbuja;
    kuz[1] = Ordenamiento<Libro>::seleccion;
    kuz[2] = Ordenamiento<Libro>::insercion;

    /*sirve para listar los libros*/
    for(auto l : libros)
    {
        cout << l;
    }

    cout << endl << "Elija una opción:\n1)burbuja\n2)insercion\n3)seleccion\n";
    cin >> choice;

    cout << "Elije la orientacion\n1)ascendente\n2)descendente\n";
    cin >> choice2;

    kuz[choice - 1](libros, n_libros, sharmutta[choice2 - 1]);

    cout << endl << "Estos son los libros ordenados" << endl;
    cout << endl;

    for(auto l : libros)
    {
        cout << l;
    }

    return 0;
}
