#include "concesionaria.h"

concesionaria::concesionaria(const string& name, int maxClientes, int maximoAutos) : name(name), maxClientes(maxClientes), maximoAutos(maximoAutos)
{
    siguienteCliente = 0;
    siguienteVenta = 0;

    if(maxClientes <= 0)
        throw "Numero de cuentas debe ser positivo";
    else
        accounts = new Cliente*[maxClientes];
}

concesionaria::~concesionaria()
{
    //dtor
}

concesionaria& concesionaria::creaCliente(int numeroCliente)
{

}

concesionaria& concesionaria::ventaCoche(int numeroCliente)
{

}

ostream& concesionaria::printCuentas(ostream& os)const
{

}

ostream& concesionaria::printCuentasCompras(ostream & os)const
{

}

ostream& operator << (ostream& os, const concesionaria& c)
{

}

Cliente& concesionaria::encuentraCliente(int cuentaCliente) const
{

}
