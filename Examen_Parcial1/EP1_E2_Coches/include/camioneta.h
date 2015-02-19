#ifndef CAMIONETA_H
#define CAMIONETA_H

#include "Auto.h"

class camioneta : public Auto
{
    int codigo;
    string marca;
    int modelo;
    int kilometraje;
    string traccion;

    ostream& print(ostream& os)const;

    public:
        camioneta(int ncodigo, string nmarca, int nmodelo, int nkilometraje, string ntraccion);

};

#endif // CAMIONETA_H
