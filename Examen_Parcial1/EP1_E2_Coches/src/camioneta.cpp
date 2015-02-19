#include "camioneta.h"

camioneta::camioneta(int ncodigo, string nmarca, int nmodelo, int nkilometraje, string ntraccion) : codigo(ncodigo), marca(nmarca), modelo(nmodelo), kilometraje(nkilometraje), traccion(ntraccion)
{
}

ostream& camioneta::print(ostream& os)const
{
    os << "El código de la camioneta es: " << codigo << " de la marca: " << marca << " Modelo del año: " << modelo << " y un kilometraje de: " << kilometraje << "km, y traccion: " << traccion << endl;
    return os;
}
