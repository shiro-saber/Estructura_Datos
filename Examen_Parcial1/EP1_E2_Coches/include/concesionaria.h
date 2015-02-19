#ifndef CONCESIONARIA_H
#define CONCESIONARIA_H

#include "Auto.h"
#include <iostream>
#include <string>
#include "Cliente.h"

using namespace std;

class concesionaria
{
    string name;
	int maxClientes;
	Cliente** accounts;
	int siguienteCliente;
	int maximoAutos;
	const Auto** transactions;
	int siguienteVenta;

	Cliente& encuentraCliente(int cuentaCliente) const;
    public:
        concesionaria(const string& name, int maxClientes, int maximoAutos);
        ~concesionaria();

        concesionaria& creaCliente(int numeroCliente);

        concesionaria& ventaCoche(int numeroCliente);

        ostream& printCuentas(ostream& os)const;
        ostream& printCuentasCompras(ostream & os)const;

        friend ostream& operator << (ostream& os, const concesionaria& c);
};

#endif // CONCESIONARIA_H
