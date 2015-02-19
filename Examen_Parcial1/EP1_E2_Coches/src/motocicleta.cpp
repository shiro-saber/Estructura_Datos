#include "motocicleta.h"

motocicleta::motocicleta(int ncodigo, string nmarca, int nmodelo, int nkilometraje, string ncilindraje) : codigo(ncodigo), marca(nmarca), modelo(nmodelo), kilometraje(nkilometraje), cilindraje(ncilindraje)
{
}

ostream& motocicleta::print(ostream& os)const
{
    os << "El código de la motocicleta es: " << codigo << " de la marca: " << marca << " Modelo del año: " << modelo << " y un kilometraje de: " << kilometraje << "km, y cilindraje: " << cilindraje << endl;
    return os;
}
