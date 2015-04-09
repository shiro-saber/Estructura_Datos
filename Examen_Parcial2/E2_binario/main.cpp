#include <cstdlib>
#include "Pila.h"


using namespace std;

Pila<int> *convierte(Pila<int> *este)
{
    while(!este->empty())
    {
        for(int i = 0; i < este->size(); ++i)
        {
           este->pop()->getInfo()%2;
           este->pop()->getNext();
        }
    }
}

int main(int argc, char** argv) 
{
    Pila<int> *convertir = new Pila<int>();
    Nodo<int> *uno = new Nodo<int>(5);
    Nodo<int> *dos = new Nodo<int>(7);
    Nodo<int> *tres = new Nodo<int>(8);
    
    convertir->push(uno);
    convertir->push(dos);
    convertir->push(tres);
    
    convierte(convertir);
    return 0;
}

