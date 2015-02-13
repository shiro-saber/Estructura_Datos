#pragma once
#include<cstdlib>
#include<iostream>
#include<string>

using namespace std;

class Libro
{
	string titulo;
	string autor;
	string editorial;
	int nPag;
	int edicion;
	int anioP;

public:
//Persona() : Persona("", "", 0) {}
    Libro() : Libro("", "", 0, 0, "", 0){}
	Libro(string nAutor,string nTitulo, int nNPag, int nEdicion, string nEditorial, int nAnioP) : titulo(nTitulo), autor(nAutor), nPag(nNPag), edicion(nEdicion), editorial (nEditorial), anioP(nAnioP) {}
    bool operator >(Libro & libro);
    bool operator <(Libro & libro);
    friend ostream & operator << (ostream & os, Libro & libro);
};
