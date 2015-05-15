#include "Libro.h"

bool Libro::operator >(Libro & libro)
{
    return altura > libro.altura;
}

bool Libro::operator <(Libro & libro)
{
    return altura < libro.altura;
}

ostream & operator << (ostream & os, Libro & libro)
{
    os << libro.titulo << ", con " << libro.nPag << " páginas y de altura " << libro.altura << endl;

    return os;
}