#include "Libro.h"

bool Libro::operator >(Libro & libro)
{
    return anioP > libro.anioP;
}

bool Libro::operator <(Libro & libro)
{
    return anioP < libro.anioP;
}

ostream & operator << (ostream & os, Libro & libro)
{
    os << libro.autor << ", " << libro.titulo << "(" << libro.anioP << "), con " << libro.nPag << " páginas y de la editorial " << libro.editorial << endl;

    return os;
}
