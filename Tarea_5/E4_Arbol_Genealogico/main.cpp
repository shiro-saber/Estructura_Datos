#include <cstdlib>
#include <iostream>
#include <string>
#include "Persona.h"
#include "ArbolBinario.h"

using namespace std;

ArbolBinario<Persona> allahUakbar;

void agregarMorro()
{
    string padre;
    string hijo;

    cout << "Padre: ";
    cin >> padre;
    cout << "Hijo: ";
    cin >> hijo;

    Persona padre(padre);
    Persona hijo(hijo);


    Nodo<Persona> * padreNodo = allahUakbar.buscar(padre);
    Nodo<Persona> * hijoNodo = new Nodo<Persona>(hijo);

    allahUakbar.Insert(padreNodo,hijoNodo);
    allahUakbar.preOrden();
}
void verDescendientes()
{
    string padreNom;
    
    cout << "Padre: ";
    cin >> padreNom;
    
    Persona padre(padreNom);
    Nodo<Persona> * padreNode = allahUakbar.buscar(padre);
    allahUakbar.preOrden();
}
void verHermanosYPrimos()
{
    string nombre;
    
    cout << "Nombre: ";
    cin >> nombre;
    
    Persona persona(nombre);
    
    Nodo<Persona> * nodo = allahUakbar.buscar(persona);
    allahUakbar.buscarPrimos(nodo);
}
void verAncestros()
{
    string padreNom;
    
    cout << "Padre: ";
    cin >> padreNom;
    
    Persona padre(padreNom);
    
    Nodo<Persona> * padreNodo = allahUakbar.buscar(padre);
    allahUakbar.ancestro(padreNodo);
}
void establecerFallecido()
{
    string nombre;
    
    cout << "Nombre fallecido: ";
    cin >> nombre;
    
    int fecha;
    
    cout << "Fecha (dia, mes, anio): ";
    cin >> fecha;

    Persona nombreP(nombre);
    Nodo<Persona> * nodo = allahUakbar.buscar(nombreP);

    if (nodo == nullptr)
    {
        cout << "Noooot!!" << endl;
    }
    else
    {
        Persona nuevaPersona = nodo->getInfo();
        nuevaPersona.setfallecido(true);
        nuevaPersona.setfecha(fecha);
        nodo->setInfo(nuevaPersona);
        
        cout << "Cambios realizados" << endl;
    }

}
void visualizarFallecidos()
{
    int fecha;
    cout << "Desde que dia murio (dia, mes, anio): ";
    cin >> fecha;
    
    allahUakbar.preOrden(allahUakbar.getRaiz(), [](Nodo<Persona> *nodo){if (nodo->getInfo().getfallecido() && nodo->getInfo().getfecha() < 12123) return true; return false;});
}
void visualizarVivos()
{
    allahUakbar.preOrden(allahUakbar.getRaiz(), [](Nodo<Persona> *nodo){if (nodo->getInfo().getfallecido()) return true; return false;});
}

int main(int argc, const char * argv[]) {

    while (true)
    {
        cout << "[1] Agregar hijo"<< endl;
        cout << "[2] Ver descendientes"<< endl;
        cout << "[3] Ver hermanos y primos"<< endl;
        cout << "[4] Ver atras"<< endl;
        cout << "[5] Establecer muerte"<< endl;
        cout << "[6] Visualizar muertos"<< endl;
        cout << "[7] Visualizar vivos"<< endl;

        int opc;
        cin >> opc;
        if (opc == 1) agregarMorro();
        else if (opc == 2) verDescendientes();
        else if (opc == 3) verHermanosYPrimos();
        else if (opc == 4) verAncestros();
        else if (opc == 5) establecerFallecido();
        else if (opc == 6) visualizarFallecidos();
        else if (opc == 7) visualizarVivos();
        else break;
    }
    return 0;
}