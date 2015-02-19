#ifndef CLIENTE_H
#define CLIENTE_H

#include "Auto.h"
#include <iostream>
#include <string>

using namespace std;

class Cliente
{
    int numeroCliente;
    string nombre;
    string apellido;
    string ife;

    public:
        Cliente();
        ~Cliente();

        Cliente& asignaVenta(const Auto& aut);

        int getNumeroCliente();

        ostream& printCuentasCompras(ostream& os)const;
};

#endif // CLIENTE_H
