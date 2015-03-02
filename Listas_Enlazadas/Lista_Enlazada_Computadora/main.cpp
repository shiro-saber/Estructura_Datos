#include <iostream>
#include <string>
#include "Node.h"
#include "Computadora.h"
#include "LinkedList.h"

using namespace std;

int main(int argc, const char * argv[]) 
{    
    using namespace vcn;
    
    Node<int> first(1);
    
    Node<float> second(3.45);
    
    Node<string> cad("Esto es una cadena");
    
    Computadora laptop;
    
    Node<Computadora> pc(laptop);
    
    cout << first << endl;
    cout << second << endl;
    cout << cad << endl;

    cout << pc << endl;
    
    LinkedList<int> * numeros  = new LinkedList<int>();
    
    /* Obtener el primer elemento */
    cout  << "First = " << numeros->first() << endl;
    
    /* Determinar el tamaño */
    cout  << "Size = " << numeros->size() << endl;
    
    /* Determinar si la lista está vacía */
    cout  << "Empty = " << (numeros->empty() ? "true" : "false") << endl;
    
    /*Insertar elementos en la lista*/
    numeros->insert(1, 0);
    numeros->insert(-1, -2);
    numeros->insert(-2, 0);
    numeros->insert(2, 10);
    numeros->insert(3, numeros->size());
    numeros->insert(5, 2);
    
    /*Imprimir el contenido de la lista*/
    cout << "Lista:" << endl << *numeros; //prueba de que lo haya anexado bien
    
    /* Determinar el tamaño */
    cout  << "Size = " << numeros->size() << endl;
    
    /* Determinar si la lista está vacía */
    cout  << "Empty = " << (numeros->empty() ? "true" : "false") << endl;
    
    /*Obtener el iesimo elemento*/
    int pos = 4;
    cout << "At(" << pos << ") = " << *(numeros->at(pos)) << endl;
    int pos2 = numeros->size()-1;
    cout << "At(" << pos2 << ") = " << *(numeros->at(pos2)) << endl;
    
    /*Obtener la posicion del elementos*/
    Node<int> * node = numeros->at(0);
    cout << "Nodo esta en posicion: " << (numeros->at(node)) << endl;
    
    /*Eliminar un nodo de la lista*/
    Node<int> * removenodo = numeros->removeFront();
    
    /*Imprimir el contenido de la lista*/
    cout << "Lista:" << endl << *numeros; //prueba de que lo haya anexado bien
    
    /* Determinar el tamaño */
    cout  << "Size = " << numeros->size() << endl;
    
    /* Determinar si la lista está vacía */
    cout  << "Empty = " << (numeros->empty() ? "true" : "false") << endl;
    
    /*Obtener el iesimo elemento*/
    cout << "At(" << pos << ") = " << *(numeros->at(pos)) << endl;
    cout << "At(" << pos2 << ") = " << *(numeros->at(pos2)) << endl;
    
    delete numeros;
    
    return 0;
}