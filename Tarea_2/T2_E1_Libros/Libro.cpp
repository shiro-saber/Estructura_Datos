#include "Libro.h"

Libro::Libro(string nAutor,string nTitulo, int nNPag, int nEdicion, string nEditorial, int nAnioP) : titulo(nTitulo), autor(nAutor), nPag(nNPag), edicion(nEdicion), editorial (nEditorial), anioP(nAnioP)
{
}

Libro::~Libro(void)
{
}

void Libro::listar(int n, Libro *biblioteca[])
{
	for(int i = 0; i < n;i++)
	{
		biblioteca[i]->imprime();
	}
}

void Libro::imprime()
{
	cout << "el libro " << titulo << " fue escrito por " << autor << endl;
	cout << "el año de publicacion es " << anioP << " es la edicion "<< edicion << " por la editorial " << editorial << endl;
}

void Libro::iAntes(int fecha, int n, Libro *biblioteca[])
{
	for(int i = 0; i < n ; i++)
	{
		if(biblioteca[i]->anioP < fecha)
		{
			biblioteca[i]->imprime();
		}
	}
	return;
}

void Libro::iDespues(int fecha, int n, Libro *biblioteca[])
{
	for(int i = 0; i < n ; i++)
	{
		if(biblioteca[i]->anioP > fecha)
		{
			biblioteca[i]->imprime();
		}
	}
	return;
}

void Libro::iEntreFechas(int inicio, int fin, int n,  Libro *biblioteca[])
{
	for(int i = 0; i < n; i++)
	{
		if((biblioteca[i]->anioP > fin) && (biblioteca[i]->anioP > inicio))
		{
			biblioteca[i]->imprime();
		}
	}
	return;
}

void Libro::iEditorial(string editorial, int n, Libro *biblioteca[])
{
	for(int i = 0; i < n ; i++)
	{
		if(editorial.compare(biblioteca[i]->editorial) == 0)
		{
			biblioteca[i]->imprime();
		}
	}
	return;
}

void Libro::iAutor(string autor, int n, Libro *biblioteca[])
{
	for(int i = 0; i < n ; i++)
	{
		if(autor.compare(biblioteca[i]->autor) == 0)
		{
			biblioteca[i]->imprime();
		}
	}
	return;
}
