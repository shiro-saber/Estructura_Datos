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
	Libro(string nAutor,string nTitulo, int nNPag, int nEdicion, string nEditorial, int nAnioP);
	~Libro(void);
	void imprime();//check
	void listar(int n,Libro *[]);//ceck
	void iAntes(int fecha, int n, Libro *biblioteca[]);//check
	void iDespues(int fecha, int n, Libro *biblioteca[]);
	void iEntreFechas(int inicio, int fin, int n,  Libro *biblioteca[]);//check
	void iAutor(string autor, int n, Libro *biblioteca[]);
	void iEditorial(string editorial, int n, Libro *biblioteca[]);
};
