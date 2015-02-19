#ifndef MOTOCICLETA_H
#define MOTOCICLETA_H

#include "Auto.h"

class motocicleta : public Auto
{
    int codigo;
    string marca;
    int modelo;
    int kilometraje;
    string cilindraje;

    ostream& print(ostream& os)const;

    public:
        motocicleta(int ncodigo, string nmarca, int nmodelo, int nkilometraje, string ncilindraje);

};

#endif // MOTOCICLETA_H
