#ifndef COCHE_H
#define COCHE_H

#include "Auto.h"

class coche : public Auto
{
    int codigo;
    string marca;
    int modelo;
    int kilometraje;

    ostream& print(ostream& os)const;
    public:
        coche(int ncodigo, string nmarca, int nmodelo, int nkilometraje);
};

#endif // COCHE_H
