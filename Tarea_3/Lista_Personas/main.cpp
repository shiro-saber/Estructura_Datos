#include <iostream>
#include "LinkedList.h"
#include "OrderedLinkedList.h"
#include "Persona.h"
#include <string>

using namespace std;

/*
Realice un programa que permita a un usuario entrar los datos de n personas y almacenarlos en
una lista enlazada ordenada, de tal manera que en todo momento las personas se encuentren
ordenadas alfabéticamente por el apellido y luego por el nombre. El usuario puede entrar tantas
personas como desee. La aplicación debe permitir en todo momento:
• Añadir una persona
• Buscar una persona
• Borrar una persona
• Visualizar los datos de todas las personas almacenadas
• Borrar todas las personas
• Determinar la cantidad de personas existentes 
 */

int main() {
    
    using namespace vcn;
    OrderedLinkedList<Persona> listaAsc(true); //siempre ordenado ascendente
    OrderedLinkedList<Persona> listaDesc(false); //cambia cuando se necesita descendente
    int choice = -1;
    int cont = 0;
    string nombre, apellidos;
    int dia, mes, anio, edad;
    vcn::Node<Persona> * kuz;

    while (choice != 0) {
        cout << "Elije\n1) Agrega una persona\n2) Buscalo\n3) Borra\n4) Quienes estan\n5) Borra Todo\n0) Salir" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Nombre de la Persona: " << endl;
                cin >> nombre;
                cout << "Apellidos de la Persona: " << endl;
                cin >> apellidos;
                cout << "Edad: " << endl;
                cin >> edad;
                cout << "Anio de nacimiento: " << endl;
                cin >> anio;
                cout << "Mes de nacimiento: " << endl;
                cin >> mes;
                cout << "Dia de nacimiento: " << endl;
                cin >> dia;

                listaAsc.insert(Persona(nombre, apellidos, edad, anio, mes, dia));
                listaDesc.insert(Persona(nombre, apellidos, edad, anio, mes, dia));
                break;
                
            case 2:
                if (listaAsc.empty()) {
                    cout << "La lista esta vacia" << endl;
                    break;
                }
                cout << "Ingrese el nombre de la persona que desea buscar: " << endl;
                cin >> nombre;
                while (cont < listaAsc.size()) {
                    kuz = listaAsc.at(cont);
                    if (kuz->getInfo().getNombre() == nombre) {
                        cout << kuz->getInfo();
                        cout << "Posicion: " << cont << endl;
                    }
                    ++cont;
                }
                cont = 0;
                break;
                
            case 3:
                int pos;
                cout << "Dame la posicion que quieres eliminar de la lista: " << endl;
                cin >> pos;
                kuz = listaAsc.remove(pos);
                delete kuz;
                kuz = nullptr;
                kuz = listaDesc.remove(listaDesc.size() - pos - 1);
                delete kuz;
                kuz = nullptr;

                break;
                
            case 4:
                cout << "1. Ascendente\n2. Descendente" << endl;
                cin >> choice;
                if (choice == 1) {
                    cout << listaAsc;
                } else {
                    cout << listaDesc;
                }
                choice = 4;

                break;
                
            case 5:
                listaAsc.clear();
                listaDesc.clear();

                break;
                
            case 0:
                cout << "Allahu'akbar" << endl;
                break;
                
            default:
                cout << "No es valida esa opcion... porque kenny! " << endl;
                break;
        }
    }

    return 0;
}

