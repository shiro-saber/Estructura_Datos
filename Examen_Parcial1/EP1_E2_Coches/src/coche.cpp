#include "coche.h"

coche::coche(int ncodigo, string nmarca, int nmodelo, int nkilometraje) : codigo(ncodigo), marca(nmarca), modelo(nmodelo), kilometraje(nkilometraje)
{
}

ostream & coche::print(ostream & os) const
{
    os << "El código del coche es: " << codigo << " de la marca: " << marca << " Modelo del año: " << modelo << " y un kilometraje de: " << kilometraje << "km." << endl;
    return os;
}
