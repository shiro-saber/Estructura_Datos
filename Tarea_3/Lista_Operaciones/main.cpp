#include <cstdlib>
#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;
using namespace vcn;

/*
Programe una aplicación que permita ingresar n números reales a una lista enlazada y m
números reales a otra lista, siendo m y n elegibles por el usuario (entrados por consola). A las
listas anteriores les llamaremos N y M respectivamente.
Después de tener ambas listas, la aplicación debe ser capaz de realizar las siguientes
operaciones:
• N ⋃ M (Los elementos duplicados deben aparecer una sola vez)
• N - M
• M - N
• N * M
• N ⋂ M
Los resultados de la operación seleccionada por el usuario deben almacenarse en otra lista
enlazada P y mostrarse por pantalla junto con la información de las listas N y M.
 */

LinkedList<int> * Union(LinkedList<int> * a, LinkedList<int> * b) {
    LinkedList<int> * temp = new LinkedList<int>();
    for (int i = 0; i < a->size(); ++i)
        temp->insertBack(a->at(i)->getInfo());
    for (int j = 0; j < b->size(); ++j) {
        bool esta = false;
        for (int k = 0; k < a->size(); ++k) {
            if (a->at(k)->getInfo() == b->at(j)->getInfo())
                esta = true;
        }
        if (!esta)
            temp->insertBack((b->at(j)->getInfo()));
    }

    return temp;
}

LinkedList<int> * Intersection(LinkedList<int> * a, LinkedList<int> * b) {
    LinkedList<int> * temp = new LinkedList<int>();
    for (int i = 0; i < a->size(); ++i)
        for (int j = 0; j < b->size(); ++j)
            if (a->at(i)->getInfo() == b->at(j)->getInfo())
                temp->insertBack(a->at(i)->getInfo());

    return temp;
}

LinkedList<int> * Product(LinkedList<int> * a, LinkedList<int> * b) {
    LinkedList<int> * temp = new LinkedList<int>();
    for (int i = 0; i < a->size(); ++i)
        for (int j = 0; j < b->size(); ++j)
            temp->insertBack(a->at(i)->getInfo() * b->at(j)->getInfo());

    return temp;
}

LinkedList<int> * Substraction(LinkedList<int> * a, LinkedList<int> * b) {
    LinkedList<int> * temp = new LinkedList<int>();
    for (int i = 0; i < a->size(); ++i) {
        bool esta = false;
        for (int j = 0; j < b->size(); ++j) {
            if (a->at(i)->getInfo() == b->at(j)->getInfo()) {
                esta = true;
                break;
            }
        }
        if (!esta)
            temp->insertBack(a->at(i)->getInfo());
    }
}

int askChoice()
{
    cout << "Elige una opcion" << endl;
    cout << "1) N ⋃ M " << endl;
    cout << "2) N - M " << endl;
    cout << "3) M - N " << endl;
    cout << "4) N * M " << endl;
    cout << "5) N ⋂ M " << endl;
    cout << "0) Exit" << endl;
    
    int choice;
    cin >> choice;
    return choice;
}

int main(int argc, char** argv) {
    int choice = askChoice();
    LinkedList<int> * lista1 = new LinkedList<int>();
    LinkedList<int> * lista2 = new LinkedList<int>();
    LinkedList<int> * temp = new LinkedList<int>();

    lista1->insert(1, 0);
    lista1->insert(-1, 1);
    lista1->insert(-2, 2);
    lista1->insert(2, 3);
    lista1->insert(5, 4);

    lista2->insert(4, 0);
    lista2->insert(1, 1);
    lista2->insert(7, 2);
    lista2->insert(9, 3);
    lista2->insert(8, 4);

    cout << "Lista1:" << endl << *lista1; //prueba de que lo haya anexado bien
    cout << "Lista2:" << endl << *lista2;
    
    switch(choice)
    {
        case 1: 
            delete temp;
            temp = Union(lista1, lista2);
            cout << "N ⋃ M: " << temp;
            break;
            
        case 2:
            delete temp;
            temp = Substraction(lista1, lista2);
            cout << "N - M: " << temp;
            break;
            
        case 3:
            delete temp; 
            temp = Substraction(lista2, lista1);
            cout << "M - N: " << temp;
            break;
            
        case 4:
            delete temp;
            temp = Product(lista1, lista2);
            cout << "N * M: " << temp;
            break;
            
        case 5:
            delete temp;
            temp = Intersection(lista1, lista2);
            cout << "N ⋂ M: " << temp;
            break;
            
        case 0:
            cout << "Bye bye";
            break;
            
        default: 
            cout << "invalido" << endl;
            break;
            
    }while (choice != 0);

    return 0;
}

