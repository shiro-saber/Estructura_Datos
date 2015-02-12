#include<cstdlib>
#include<iostream>
#include<string>
#include"Libro.h"
#define N 3

using namespace std;

/*
Programe una aplicación que permita llevar el control de libros en una biblioteca. De cada libro
se conoce el título, autor, número de páginas, edición, editorial y año de publicación. La
aplicación debe permitir:
    • Adicionar libros
    • Eliminar libros
    • Mostrar los libros que se hayan publicado antes de una fecha dada.
    • Mostrar los libros que se hayan publicado después de una fecha dada.
    • Mostrar los libros que se hayan publicado en un período de tiempo determinado.
    • Mostrar los libros escritos por un autor
    • Mostrar los libros publicados por una editorial
*/

Libro * biblioteca[N];

void agregar(int &pos)
{
	string autor;
	string titulo;
	int pag;
	int edicion;
	string editorial;
	int anio;

	cout << "inserte titulo" << endl;
	cin >> titulo;
	cout << "inserte autor" << endl;
	cin >> autor;
	cout << "inserte numero de paginas" << endl;
	cin >> pag;
	cout << "inserte numero de edicion" << endl;
	cin >> edicion;
	cout << "inserte editorial" << endl;
	cin >> editorial;
	cout << "inserte año de publicacion" << endl;
	cin >> anio;

	biblioteca[pos]=new Libro(autor,titulo,pag,edicion,editorial,anio);

	pos++;
	return;
}

void eliminar()
{
	int pos =0;

	cout << "que libro desea eliminar (su posision)" << endl;
	cin >> pos;

	biblioteca[pos] = NULL;

	return;
}

int askChoice()
{
	cout << "1) agregar libro" << endl;
	cout << "2) borrar libro" << endl;
	cout << "3) muestra los libros de la biblioteca" << endl;
	cout << "4) buscar por fecha anterior a un año de publicacion" << endl;
	cout << "5) buscar por fecha posterior a un año de publicacion" << endl;
	cout << "6) buscar los libros que que se publicaron entre 2 años" << endl;
	cout << "7) buscar por editorial" << endl;
	cout << "8) buscar por autor" << endl;
	cout << "0) salir" << endl;

	int choice;

	cin >> choice;

	return choice;
}

int main()
{
	int pos = 0;
	int choice = 0;
	int n;
	int fecha;
	int ini;
	int fin;
	string zain;
    n = N;

	do
	{
		choice= askChoice();
		switch(choice)
		{
		case 1:
			agregar(pos);
			break;

		case 2:
			eliminar();
			break;

		case 3:
			biblioteca[pos]->listar(n,biblioteca);
			break;

		case 4:
			cout << " antes de que fecha desea buscar" << endl;
			cin >> fecha;
			biblioteca[pos]->iAntes(fecha,n,biblioteca);
			break;

		case 5:
			cout << " despues de que fecha desea buscar" << endl;
			cin >> fecha;
			biblioteca[pos]->iDespues(fecha,n,biblioteca);
			break;

		case 6:
			cout << " primera fecha para buscar" << endl;
			cin >> ini;
			cout << " ultima fecha para buscar" << endl;
			cin >> fin;
			biblioteca[pos]->iEntreFechas(ini,fin,n,biblioteca);
			break;

		case 7:
			cout << "que editorial deasea buscar" << endl;
			cin >> zain;
			biblioteca[pos]->iEditorial(zain,n,biblioteca);
			break;

		case 8:
			cout << "que autora deasea buscar" << endl;
			cin >> zain;
			biblioteca[pos]->iAutor(zain,n,biblioteca);
			break;

        case 0:
            cout << "Bye!" << endl;
            break;

		default:
            cout << " opcion invalida " << endl;
			break;
		}
	}while(choice != 0);

	return 0;
}
