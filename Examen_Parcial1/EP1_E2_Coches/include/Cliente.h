#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>

using namespace std;

class Cliente
{
    string nombre;
    string apellido;
    string ife;

    public:
        Cliente();
        ~Cliente();
};

#endif // CLIENTE_H
