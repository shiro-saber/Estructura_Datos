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
    
    delete numeros;
    
    return 0;
}